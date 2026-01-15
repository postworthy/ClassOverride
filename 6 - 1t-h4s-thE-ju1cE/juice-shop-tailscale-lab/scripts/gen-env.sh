#!/usr/bin/env bash
set -euo pipefail

if ! command -v tailscale >/dev/null 2>&1; then
  echo "ERROR: 'tailscale' command not found. Install Tailscale and ensure it's running."
  exit 1
fi

TS_IP="$(tailscale ip -4 | head -n1 | tr -d '\r\n')"

if [[ -z "${TS_IP}" ]]; then
  echo "ERROR: Unable to determine Tailscale IPv4. Is Tailscale up?"
  exit 1
fi

cat > .env <<EOF
TS_IP=${TS_IP}
EOF

echo "Wrote .env with TS_IP=${TS_IP}"
