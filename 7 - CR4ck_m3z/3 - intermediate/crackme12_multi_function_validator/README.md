# Crackme 12: Multi-Function Validator

## Difficulty
Intermediate

## Challenge Intent
Distribute the validation logic across multiple helper functions so students must trace the full call graph.

## Student Goal
Understand how each helper contributes to acceptance and derive a valid input.

## Learning Objectives
- Build a mental model from several functions instead of one
- Track parameters and return values across calls
- Identify which helpers are meaningful and which are setup

## Planned Implementation Notes
- One coordinator function
- Several focused helper routines
- At least one helper transforms data for another helper

## Intended Solve Path
Students should use a decompiler or debugger to connect the helper functions into one coherent validation story.

## Constraints
- Keep naming stripped in the student binary
- Avoid unnecessary boilerplate code
