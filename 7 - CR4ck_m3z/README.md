# Crackme Curriculum

This repository is a scaffold for a small reverse-engineering curriculum built around intentionally vulnerable "crackme" style C programs. The goal is to give cyber security students realistic but controlled binaries they can analyze, patch, and solve as they build binary reversing skills.

## Structure

The repository is organized by difficulty:

- `1 - beginner`
- `2 - early-intermediate`
- `3 - intermediate`
- `4 - advanced`

Each difficulty directory contains several individual crackme challenge folders. Each challenge folder currently includes a `README.md` that defines:

- the intent of the challenge
- the student goal
- the primary learning objectives
- planned implementation notes
- the intended solve path
- design constraints

## Planned Challenge Progression

### Beginner

These challenges focus on the fundamentals of static and dynamic analysis.

- `crackme01_literal_password`
- `crackme02_split_string`
- `crackme03_position_checks`
- `crackme04_xor_obfuscation`
- `crackme05_multistage_branches`

### Early Intermediate

These challenges shift from extracting a secret to understanding how a program derives or routes validation logic.

- `crackme06_serial_checksum`
- `crackme07_hidden_trigger`
- `crackme08_username_to_key`
- `crackme09_indirect_dispatch`
- `crackme10_runtime_flag`

### Intermediate

These challenges require broader tracing, more deliberate reasoning, and basic patching strategy.

- `crackme11_anti_strings`
- `crackme12_multi_function_validator`
- `crackme13_custom_hash`
- `crackme14_patch_me`
- `crackme15_state_machine`

### Advanced

These challenges introduce lightweight defensive techniques and more abstract execution models.

- `crackme16_anti_debug`
- `crackme17_self_integrity`
- `crackme18_runtime_unpack`
- `crackme19_bytecode_vm`
- `crackme20_multiple_paths`

## Teaching Approach

The intended progression is incremental. Each crackme should teach one main concept clearly instead of mixing too many ideas into a single binary. That keeps the challenge teachable, easier to debug, and easier to map to classroom objectives.

General design goals:

- keep programs small and readable in source form
- make binaries solvable with common reversing tools
- avoid malware-like behavior, persistence, networking, or destructive actions
- separate student-facing binaries from instructor notes and solutions
- prefer deterministic challenge logic over randomness

## Recommended Implementation Pattern

As we build each crackme, each challenge directory should eventually include:

- `README.md` with the challenge description
- `src/` for source files
- `build/` or documented compiler instructions if needed
- optional `solution/` or instructor-only notes kept separate from student handouts

For each completed challenge, we should also decide:

- the intended toolset for students
- whether the expected solve path is static, dynamic, or patch-based
- whether multiple valid solve paths should exist
- what artifacts are distributed to students

## Suggested Next Steps

1. Implement the first three beginner crackmes in C.
2. Add consistent build instructions for compiling stripped student binaries and unstripped instructor binaries.
3. Add instructor notes or solve guides for each completed challenge.
4. Decide whether to keep all binaries Linux ELF only for the first version.

## Notes

This repository is intended for legal, ethical, classroom-style reverse engineering practice. The challenges should remain instructional, bounded, and safe to run in a lab environment.
