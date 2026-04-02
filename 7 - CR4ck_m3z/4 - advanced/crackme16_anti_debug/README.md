# Crackme 16: Anti-Debug

## Difficulty
Advanced

## Challenge Intent
Introduce basic anti-debugging so students must recognize and bypass debugger detection before solving the core validation logic.

## Student Goal
Neutralize or work around the anti-debug check and then solve the crackme normally.

## Learning Objectives
- Identify common anti-debug techniques such as `ptrace`
- Separate defensive code from validation code
- Practice bypassing checks through patching or debugger setup

## Planned Implementation Notes
- One lightweight anti-debug check near startup
- Clear alternate behavior when a debugger is detected
- Core password logic remains solvable after bypass

## Intended Solve Path
Students should first defeat the anti-debug measure, then continue with standard reversing.

## Constraints
- Keep protection minimal and instructional
- No kernel tricks or hostile behavior
