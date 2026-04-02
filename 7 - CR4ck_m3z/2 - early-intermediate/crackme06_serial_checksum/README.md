# Crackme 06: Serial Checksum

## Difficulty
Early Intermediate

## Challenge Intent
Accept a serial key in a fixed format such as `XXXX-XXXX-XXXX` and validate it with checksum-style rules.

## Student Goal
Generate or derive a serial that passes all validation checks.

## Learning Objectives
- Reverse input parsing and format enforcement
- Understand checksum logic and arithmetic validation
- Differentiate syntax checks from semantic checks

## Planned Implementation Notes
- Parse grouped input with separators
- Enforce character class and length rules
- Use a deterministic checksum over sections

## Intended Solve Path
Students should recover the checksum algorithm and produce a valid serial, not just extract a literal string.

## Constraints
- Keep the math lightweight
- Ensure multiple invalid inputs fail at different stages
