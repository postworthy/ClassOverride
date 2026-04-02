# Crackme 09: Indirect Dispatch

## Difficulty
Early Intermediate

## Challenge Intent
Route validation through a function pointer table or compact jump-table style dispatcher.

## Student Goal
Understand the indirect control flow and recover the complete validation logic.

## Learning Objectives
- Follow function pointers in decompiler output
- Recognize compiler-generated indirect branching
- Build a call graph from less obvious control flow

## Planned Implementation Notes
- Several small validator functions
- Dispatcher selects validators in sequence
- Final result depends on all dispatched checks passing

## Intended Solve Path
Students should identify each indirect target and reconstruct the order of execution.

## Constraints
- Indirection should be purposeful, not chaotic
- Keep helper functions short
