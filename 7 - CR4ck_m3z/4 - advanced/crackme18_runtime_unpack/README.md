# Crackme 18: Runtime Unpack

## Difficulty
Advanced

## Challenge Intent
Keep the main validation routine encoded until runtime, forcing students to inspect the unpacking step dynamically.

## Student Goal
Reach the unpacked code or data and recover the actual validation logic.

## Learning Objectives
- Observe staged decoding or unpacking behavior
- Identify when static disassembly is insufficient
- Capture decoded memory during execution

## Planned Implementation Notes
- Encoded block stored in data
- Small unpack routine reconstructs executable logic or validation tables
- Final validation occurs only after unpacking

## Intended Solve Path
Students should trace the unpack step and inspect the resulting memory rather than rely only on static tools.

## Constraints
- Keep the unpacking mechanism simple and visible
- Do not implement anything malware-like
