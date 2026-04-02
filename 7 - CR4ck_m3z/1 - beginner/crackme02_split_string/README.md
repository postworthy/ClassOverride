# Crackme 02: Split String

## Difficulty
Beginner

## Challenge Intent
Hide the password by splitting it across several local variables or small character arrays rather than storing it as one obvious string.

## Student Goal
Reconstruct the full expected password from the compiled binary.

## Learning Objectives
- Read string fragments from assembly or decompiler output
- Understand how compilers materialize stack-local constants
- Practice rebuilding program data manually

## Planned Implementation Notes
- Password assembled from multiple fragments
- Final comparison still straightforward once reconstructed
- Minimal branching to keep the focus on data recovery

## Intended Solve Path
Students should inspect disassembly or decompiler output and piece the password together.

## Constraints
- Keep the algorithm simple
- Avoid introducing encoding yet
