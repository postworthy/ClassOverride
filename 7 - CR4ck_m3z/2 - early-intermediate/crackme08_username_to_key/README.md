# Crackme 08: Username to Key

## Difficulty
Early Intermediate

## Challenge Intent
Require the user to provide both a username and a derived serial key generated from that username.

## Student Goal
Reverse the key generation algorithm and compute a valid key for any chosen username.

## Learning Objectives
- Analyze deterministic transforms over user input
- Separate input normalization from key generation
- Reimplement reversed logic in a helper script if desired

## Planned Implementation Notes
- Two input fields or two command-line arguments
- Algorithm combines length, position, and arithmetic transforms
- No hard-coded final key in the binary

## Intended Solve Path
Students should recover the algorithm and synthesize a correct output rather than search for a secret string.

## Constraints
- Keep the algorithm readable in assembly
- No cryptographic primitives
