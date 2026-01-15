#!/usr/bin/env bash
set -euo pipefail

if ! command -v ufw >/dev/null 2>&1; then
  echo "ERROR: ufw not found. Install with your distro package manager (e.g., apt install ufw)."
  exit 1
fi

echo "This will:"
echo "  - set default incoming policy to DENY"
echo "  - allow TCP 3000-3099 inbound ONLY on tailscale0"
echo "  - enable ufw (if not already enabled)"
echo
read -r -p "Proceed? [y/N] " ans
if [[ "${ans}" != "y" && "${ans}" != "Y" ]]; then
  echo "Aborted."
  exit 0
fi

sudo ufw default deny incoming
sudo ufw allow in on tailscale0 to any port 3000:3099 proto tcp
sudo ufw enable

echo "Done. Verify with: sudo ufw status verbose"
