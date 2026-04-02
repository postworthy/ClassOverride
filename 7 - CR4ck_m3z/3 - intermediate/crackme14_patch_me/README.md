# Crackme 14: Patch Me

## Difficulty
Intermediate

## Challenge Intent
Design a challenge where binary patching is the intended shortest path to success.

## Student Goal
Modify the compiled binary so it always reaches the success branch.

## Learning Objectives
- Identify a decisive conditional jump
- Patch instructions safely without breaking execution
- Compare solving by patching versus solving by analysis

## Planned Implementation Notes
- Straightforward failure and success branches
- One obvious conditional gate near the end
- Instructor version should document the expected patch site

## Intended Solve Path
Students should inspect the final comparison and patch the relevant branch or return value.

## Constraints
- No integrity checks in this challenge
- Program should still be analyzable without patching
