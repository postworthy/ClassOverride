# Instructor Notes

This directory contains helper scripts and documentation for building, validating, and distributing the crackme challenges.

## Build Layout

Each crackme's `build.sh` now produces two binaries:

- `build/instructor/<crackme-name>`
- `build/student/<crackme-name>`

The instructor binary is intended for internal use and includes debug symbols:

- compiled with `-O0 -g`

The student binary is intended for classroom distribution and is easier to use as a reversing target:

- compiled with `-O0`
- stripped with `-s`
- built with `-fno-stack-protector`
- built with `-no-pie`

## Helper Scripts

### `build_crackme.sh`

Shared build helper used by every crackme-specific `build.sh`.

Example:

```bash
./instructors/build_crackme.sh crackme01 "1 - beginner/crackme01_literal_password/src/main.c"
```

### `validate_known_good.sh`

Builds every crackme and runs each one with a known-good solution path.

Example:

```bash
./instructors/validate_known_good.sh
```

This is the main regression check instructors should run after making changes to any challenge.

## Known-Good Inputs

These values are used by `validate_known_good.sh`.

### Beginner

- `crackme01_literal_password`: `swordfish`
- `crackme02_split_string`: `shadow_stack`
- `crackme03_position_checks`: `R3v_mn!?`
- `crackme04_xor_obfuscation`: `icepick`
- `crackme05_multistage_branches`: `lab-42!RE`

### Early Intermediate

- `crackme06_serial_checksum`: `R3V5-CL4S-6K11`
- `crackme07_hidden_trigger`: input `guest` with argument `--staff`
- `crackme08_username_to_key`: username `ALICE`, key `1384-82-5A`
- `crackme09_indirect_dispatch`: `JMP42!`
- `crackme10_runtime_flag`: `trace_me`

### Intermediate

- `crackme11_anti_strings`: `silent_step`
- `crackme12_multi_function_validator`: `CallGraph`
- `crackme13_custom_hash`: `spinlock`
- `crackme14_patch_me`: `letmein`
- `crackme15_state_machine`: `FSM-2026`

### Advanced

- `crackme16_anti_debug`: `breakfree`
- `crackme17_self_integrity`: `integrity`
- `crackme18_runtime_unpack`: `unpack_me`
- `crackme19_bytecode_vm`: `vm42!`
- `crackme20_multiple_paths`: input `audit` with argument `--maintenance`

## Suggested Instructor Workflow

1. Edit or add challenge code in the relevant crackme directory.
2. Run that crackme's `build.sh`.
3. Run `./instructors/validate_known_good.sh` before distributing updated binaries.
4. Distribute the binary from the crackme's `build/student/` directory.
5. Keep the `build/instructor/` binary for debugging, demos, and walkthroughs.

## Distribution Notes

- Student binaries are intentionally instructional, not hardened.
- Some advanced crackmes include simple anti-debugging or integrity checks, but all remain classroom-safe.
- If you change any expected solution, update both the challenge source and `validate_known_good.sh`.
