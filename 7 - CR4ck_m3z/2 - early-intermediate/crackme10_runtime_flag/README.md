# Crackme 10: Runtime Flag

## Difficulty
Early Intermediate

## Challenge Intent
Reconstruct the success token or flag only at runtime from encoded fragments so it does not appear directly in static strings.

## Student Goal
Recover the generated value and understand how the program assembles it.

## Learning Objectives
- Track data as it moves through temporary buffers
- Recover values that only exist after runtime transformation
- Use debugger memory inspection effectively

## Planned Implementation Notes
- Store fragments in arrays or tables
- Reassemble and transform them during execution
- Compare the generated flag against user input

## Intended Solve Path
Students can solve by reversing the assembly logic or observing the reconstructed buffer during execution.

## Constraints
- Limit the number of transform steps
- Keep the runtime generation deterministic
