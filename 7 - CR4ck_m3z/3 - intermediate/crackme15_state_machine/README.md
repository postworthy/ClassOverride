# Crackme 15: State Machine

## Difficulty
Intermediate

## Challenge Intent
Validate input with a compact state machine that evolves per character and only accepts one correct sequence.

## Student Goal
Reconstruct the expected transitions and determine an accepted input.

## Learning Objectives
- Model control flow as state transitions
- Track persistent state across a loop
- Translate lower-level logic into a higher-level diagram

## Planned Implementation Notes
- Enumerated states or integer state values
- One loop over the input string
- Success depends on the final state after all characters are processed

## Intended Solve Path
Students should map state transitions and derive the path to the accepting state.

## Constraints
- Keep the number of states limited
- Avoid opaque, compiler-hostile constructs
