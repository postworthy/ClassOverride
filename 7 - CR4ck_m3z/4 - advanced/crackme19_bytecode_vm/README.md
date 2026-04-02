# Crackme 19: Bytecode VM

## Difficulty
Advanced

## Challenge Intent
Interpret password validation logic through a tiny custom virtual machine instead of native branches.

## Student Goal
Reverse the VM instruction set and determine what bytecode behavior leads to success.

## Learning Objectives
- Recover an abstract instruction set from C code
- Separate VM engine behavior from challenge-specific bytecode
- Reason about a higher-level execution model during reversing

## Planned Implementation Notes
- Tiny instruction dispatcher
- Small bytecode program embedded in the binary
- VM manipulates an accumulator or small register set while processing input

## Intended Solve Path
Students should document the VM operations and then emulate or manually analyze the bytecode.

## Constraints
- Keep the instruction set very small
- Ensure the VM remains teachable within a class setting
