#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_SCRIPT="${SCRIPT_DIR}/build.sh"
PROGRAM="${SCRIPT_DIR}/build/instructor/crackme16"

if [[ "${1:-}" == "build" ]]; then
    "${BUILD_SCRIPT}"
fi

if [[ ! -x "${PROGRAM}" ]]; then
    "${BUILD_SCRIPT}"
fi

exec "${PROGRAM}"
