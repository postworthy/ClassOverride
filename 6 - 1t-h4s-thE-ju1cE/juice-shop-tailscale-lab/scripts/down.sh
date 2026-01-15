#!/usr/bin/env bash
set -euo pipefail

# Bring the stack down hard
docker compose down --remove-orphans --volumes || true

# Extra cleanup: remove any leftover containers from this compose project (belt & suspenders)
project_name="$(basename "$(pwd)")"
# Compose v2 typically labels containers with com.docker.compose.project=<project>
mapfile -t leftovers < <(docker ps -a -q --filter "label=com.docker.compose.project=${project_name}")

if [[ "${#leftovers[@]}" -gt 0 ]]; then
  echo "Removing leftover containers for project ${project_name}..."
  docker rm -f "${leftovers[@]}" >/dev/null 2>&1 || true
fi

echo "Down complete. Next up will start from scratch."
