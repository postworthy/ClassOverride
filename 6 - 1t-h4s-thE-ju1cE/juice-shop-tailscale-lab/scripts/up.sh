#!/usr/bin/env bash
set -euo pipefail

N="${1:-4}"

if [[ ! -f .env ]]; then
  echo "No .env found. Generating it now..."
  ./scripts/gen-env.sh
fi

# Pull image first so startup is faster/predictable
docker compose pull

# Start N replicas
docker compose up -d --scale juice-shop="${N}"

echo
echo "Running ${N} Juice Shop instances bound to TS_IP from .env."
echo "Team URLs (ports start at 3000):"
TS_IP="$(grep '^TS_IP=' .env | cut -d= -f2)"
for ((i=0; i<N; i++)); do
  port=$((3000+i))
  echo "  Team $((i+1)): http://${TS_IP}:${port}"
done
