# Crackme 01: Literal Password

## Difficulty
Beginner

## Challenge Intent
Create the simplest possible crackme: a console program that reads a password and compares it against a hard-coded literal.

## Student Goal
Recover the correct password and trigger the success message.

## Learning Objectives
- Identify obvious secrets with `strings`
- Recognize a direct `strcmp`-style check in disassembly
- Understand the basic crackme workflow from input to branch to success

## Planned Implementation Notes
- Single source file
- One prompt for input
- One direct password comparison
- Clear success and failure paths

## Intended Solve Path
Students should be able to solve this statically with very little friction.

## Constraints
- No obfuscation
- No anti-debugging
- No patching required
