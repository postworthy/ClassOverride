#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 2 ]]; then
    echo "usage: $0 <crackme-name> <source-file>" >&2
    exit 1
fi

CRACKME_NAME="$1"
SOURCE_FILE="$2"
SOURCE_DIR="$(cd "$(dirname "${SOURCE_FILE}")" && pwd)"
PROJECT_DIR="$(cd "${SOURCE_DIR}/.." && pwd)"
BUILD_DIR="${PROJECT_DIR}/build"
INSTRUCTOR_DIR="${BUILD_DIR}/instructor"
STUDENT_DIR="${BUILD_DIR}/student"
INSTRUCTOR_BIN="${INSTRUCTOR_DIR}/${CRACKME_NAME}"
STUDENT_BIN="${STUDENT_DIR}/${CRACKME_NAME}"

mkdir -p "${INSTRUCTOR_DIR}" "${STUDENT_DIR}"

cc -Wall -Wextra -O0 -g "${SOURCE_FILE}" -o "${INSTRUCTOR_BIN}"
cc -Wall -Wextra -O0 -fno-stack-protector -no-pie -s "${SOURCE_FILE}" -o "${STUDENT_BIN}"

echo "Built instructor binary: ${INSTRUCTOR_BIN}"
echo "Built student binary: ${STUDENT_BIN}"
