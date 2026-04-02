# Crackme 04: XOR Obfuscation

## Difficulty
Beginner

## Challenge Intent
Store an obfuscated password in the binary and decode it at runtime with a fixed XOR key.

## Student Goal
Recover the unobfuscated password or replicate the decode routine.

## Learning Objectives
- Identify a simple encoding pattern
- Trace a small decode loop
- Distinguish between stored bytes and runtime values

## Planned Implementation Notes
- Byte array in the binary instead of plain text
- Single-byte XOR decode routine
- Standard success comparison after decoding

## Intended Solve Path
Students can solve either by reversing the decode logic or by observing decoded memory at runtime.

## Constraints
- One encoding step only
- No anti-analysis behavior
