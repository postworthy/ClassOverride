#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/../.." && pwd)"

"${ROOT_DIR}/instructors/build_crackme.sh" crackme05 "${SCRIPT_DIR}/src/main.c"
