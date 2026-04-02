# Crackme 13: Custom Hash

## Difficulty
Intermediate

## Challenge Intent
Validate input by hashing it with a small custom routine and comparing the final accumulator against a target constant.

## Student Goal
Reverse or satisfy the custom hash routine to find valid input.

## Learning Objectives
- Analyze iterative state updates over user input
- Distinguish a toy hash from encryption
- Consider multiple solve strategies, including symbolic reasoning or guided brute force

## Planned Implementation Notes
- Simple custom accumulator, rotates, XOR, and additions
- Fixed target value embedded in the binary
- Length restrictions to keep the search space manageable

## Intended Solve Path
Students should understand the routine deeply enough to derive or search for a passing input.

## Constraints
- Keep it solvable without specialized tooling
- Avoid real cryptographic hashes
