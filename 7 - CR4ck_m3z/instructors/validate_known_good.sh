#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

run_case() {
    local name="$1"
    local command="$2"

    echo "[*] ${name}"
    if ! bash -lc "cd '${ROOT_DIR}' && ${command}" >/dev/null; then
        echo "[!] Failed: ${name}" >&2
        exit 1
    fi
}

for d in \
    "1 - beginner/crackme01_literal_password" \
    "1 - beginner/crackme02_split_string" \
    "1 - beginner/crackme03_position_checks" \
    "1 - beginner/crackme04_xor_obfuscation" \
    "1 - beginner/crackme05_multistage_branches" \
    "2 - early-intermediate/crackme06_serial_checksum" \
    "2 - early-intermediate/crackme07_hidden_trigger" \
    "2 - early-intermediate/crackme08_username_to_key" \
    "2 - early-intermediate/crackme09_indirect_dispatch" \
    "2 - early-intermediate/crackme10_runtime_flag" \
    "3 - intermediate/crackme11_anti_strings" \
    "3 - intermediate/crackme12_multi_function_validator" \
    "3 - intermediate/crackme13_custom_hash" \
    "3 - intermediate/crackme14_patch_me" \
    "3 - intermediate/crackme15_state_machine" \
    "4 - advanced/crackme16_anti_debug" \
    "4 - advanced/crackme17_self_integrity" \
    "4 - advanced/crackme18_runtime_unpack" \
    "4 - advanced/crackme19_bytecode_vm" \
    "4 - advanced/crackme20_multiple_paths"
do
    (cd "${ROOT_DIR}/${d}" && ./build.sh) >/dev/null
done

run_case "crackme01" "printf '%s\n' 'swordfish' | \"1 - beginner/crackme01_literal_password/run.sh\""
run_case "crackme02" "printf '%s\n' 'shadow_stack' | \"1 - beginner/crackme02_split_string/run.sh\""
run_case "crackme03" "printf '%s\n' 'R3v_mn!?' | \"1 - beginner/crackme03_position_checks/run.sh\""
run_case "crackme04" "printf '%s\n' 'icepick' | \"1 - beginner/crackme04_xor_obfuscation/run.sh\""
run_case "crackme05" "printf '%s\n' 'lab-42!RE' | \"1 - beginner/crackme05_multistage_branches/run.sh\""
run_case "crackme06" "printf '%s\n' 'R3V5-CL4S-6K11' | \"2 - early-intermediate/crackme06_serial_checksum/run.sh\""
run_case "crackme07" "printf '%s\n' 'guest' | \"2 - early-intermediate/crackme07_hidden_trigger/run.sh\" --staff"
run_case "crackme08" "printf '%s\n%s\n' 'ALICE' '1384-82-5A' | \"2 - early-intermediate/crackme08_username_to_key/run.sh\""
run_case "crackme09" "printf '%s\n' 'JMP42!' | \"2 - early-intermediate/crackme09_indirect_dispatch/run.sh\""
run_case "crackme10" "printf '%s\n' 'trace_me' | \"2 - early-intermediate/crackme10_runtime_flag/run.sh\""
run_case "crackme11" "printf '%s\n' 'silent_step' | \"3 - intermediate/crackme11_anti_strings/run.sh\""
run_case "crackme12" "printf '%s\n' 'CallGraph' | \"3 - intermediate/crackme12_multi_function_validator/run.sh\""
run_case "crackme13" "printf '%s\n' 'spinlock' | \"3 - intermediate/crackme13_custom_hash/run.sh\""
run_case "crackme14" "printf '%s\n' 'letmein' | \"3 - intermediate/crackme14_patch_me/run.sh\""
run_case "crackme15" "printf '%s\n' 'FSM-2026' | \"3 - intermediate/crackme15_state_machine/run.sh\""
run_case "crackme16" "printf '%s\n' 'breakfree' | \"4 - advanced/crackme16_anti_debug/run.sh\""
run_case "crackme17" "printf '%s\n' 'integrity' | \"4 - advanced/crackme17_self_integrity/run.sh\""
run_case "crackme18" "printf '%s\n' 'unpack_me' | \"4 - advanced/crackme18_runtime_unpack/run.sh\""
run_case "crackme19" "printf '%s\n' 'vm42!' | \"4 - advanced/crackme19_bytecode_vm/run.sh\""
run_case "crackme20" "printf '%s\n' 'audit' | \"4 - advanced/crackme20_multiple_paths/run.sh\" --maintenance"

echo "[+] All known-good checks passed."
