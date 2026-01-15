#!/usr/bin/env bash
set -euo pipefail

docker compose ps

echo
echo "URLs:"
TS_IP="$(grep '^TS_IP=' .env 2>/dev/null | cut -d= -f2 || true)"
if [[ -z "${TS_IP}" ]]; then
  TS_IP="<TS_IP not set>"
fi

mapfile -t CIDS < <(docker compose ps -q juice-shop)
i=1
for cid in "${CIDS[@]}"; do
  host_port="$(docker inspect -f '{{(index (index .NetworkSettings.Ports "3000/tcp") 0).HostPort}}' "$cid" 2>/dev/null || true)"
  if [[ -n "${host_port}" ]]; then
    echo "  Team ${i}: http://${TS_IP}:${host_port}"
  else
    echo "  Team ${i}: (no published port) container=${cid}"
  fi
  ((i++))
done
