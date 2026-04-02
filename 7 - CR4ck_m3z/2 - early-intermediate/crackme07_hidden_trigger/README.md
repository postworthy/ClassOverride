# Crackme 07: Hidden Trigger

## Difficulty
Early Intermediate

## Challenge Intent
Add a non-obvious alternate path that depends on a command-line argument, environment variable, or hidden mode switch.

## Student Goal
Discover the hidden trigger and use it to reach the success path.

## Learning Objectives
- Inspect program startup and argument handling
- Look beyond the main input prompt for relevant behavior
- Recognize alternate execution paths in a small binary

## Planned Implementation Notes
- Standard password prompt remains visible
- Hidden path bypasses or alters normal validation
- Trigger is discoverable through analysis, not brute force

## Intended Solve Path
Students should inspect `main`, startup helpers, or strings related to argument names and hidden modes.

## Constraints
- Hidden behavior should be intentional and teachable
- Avoid relying on undocumented platform quirks
