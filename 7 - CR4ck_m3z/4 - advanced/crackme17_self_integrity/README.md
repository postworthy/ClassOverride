# Crackme 17: Self-Integrity

## Difficulty
Advanced

## Challenge Intent
Detect simple binary patching by checking the integrity of a small code or data region before accepting input.

## Student Goal
Understand the integrity check and either preserve it while solving or bypass it cleanly.

## Learning Objectives
- Recognize integrity verification patterns
- See how tamper detection changes patching strategy
- Distinguish code regions from data regions used in verification

## Planned Implementation Notes
- Compute a checksum over a stable region
- Refuse execution or success if the checksum changes
- Keep the verified range small and documented for instructors

## Intended Solve Path
Students should decide whether to solve without patching or patch both the check and the validator deliberately.

## Constraints
- No self-modifying code
- Avoid platform-fragile tricks where possible
