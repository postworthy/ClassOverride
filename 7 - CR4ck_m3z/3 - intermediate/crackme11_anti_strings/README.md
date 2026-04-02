# Crackme 11: Anti-Strings

## Difficulty
Intermediate

## Challenge Intent
Prevent an easy `strings` solve by storing all important data as byte arrays that are decoded only during execution.

## Student Goal
Recover the secret despite the lack of meaningful static strings.

## Learning Objectives
- Recognize the limits of superficial static analysis
- Recover data from decode routines
- Use dynamic analysis to inspect transient values

## Planned Implementation Notes
- Avoid plain-text prompts for sensitive data
- Decode data into temporary stack or heap buffers
- Use helper functions to separate storage and decode

## Intended Solve Path
Students should move beyond `strings` and inspect either the decode routine or runtime memory.

## Constraints
- No heavy obfuscation
- Still suitable for classroom walkthroughs
