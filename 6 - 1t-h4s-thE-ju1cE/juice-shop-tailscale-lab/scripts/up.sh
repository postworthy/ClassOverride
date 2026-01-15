#!/usr/bin/env bash
set -euo pipefail

N="${1:-4}"

if [[ ! -f .env ]]; then
  echo "No .env found. Generating it now..."
  ./scripts/gen-env.sh
fi

docker compose pull
docker compose up -d --scale juice-shop="${N}"

echo
echo "Discovering live port mappings (container :3000 -> host port)…"
TS_IP="$(grep '^TS_IP=' .env | cut -d= -f2)"

# List containers for this service in a stable order
mapfile -t CIDS < <(docker compose ps -q juice-shop)

if [[ "${#CIDS[@]}" -eq 0 ]]; then
  echo "No containers found for service 'juice-shop'."
  exit 1
fi

i=1
for cid in "${CIDS[@]}"; do
  # Find the published host port for container port 3000/tcp
  host_port="$(docker inspect -f '{{(index (index .NetworkSettings.Ports "3000/tcp") 0).HostPort}}' "$cid" 2>/dev/null || true)"

  if [[ -z "${host_port}" ]]; then
    echo "  Team ${i}: (no published port found yet) container=${cid}"
  else
    # If you bound to TS_IP in compose.yml, the host is TS_IP; otherwise it's whatever bind address you used.
    echo "  Team ${i}: http://${TS_IP}:${host_port}"
  fi
  ((i++))
done
