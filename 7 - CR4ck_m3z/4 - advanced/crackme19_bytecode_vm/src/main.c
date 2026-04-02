#include <stdio.h>
#include <string.h>

enum {
    OP_LEN = 1,
    OP_LOAD = 2,
    OP_XOR = 3,
    OP_CMP = 4,
    OP_HALT = 0xff
};

static int run_vm(const unsigned char *program, size_t size, const char *input) {
    size_t pc = 0;
    unsigned char acc = 0;

    while (pc < size) {
        unsigned char opcode = program[pc++];

        switch (opcode) {
            case OP_LEN:
                if (pc >= size || strlen(input) != program[pc++]) {
                    return 0;
                }
                break;
            case OP_LOAD:
                if (pc >= size || program[pc] >= strlen(input)) {
                    return 0;
                }
                acc = (unsigned char)input[program[pc++]];
                break;
            case OP_XOR:
                if (pc >= size) {
                    return 0;
                }
                acc ^= program[pc++];
                break;
            case OP_CMP:
                if (pc >= size || acc != program[pc++]) {
                    return 0;
                }
                break;
            case OP_HALT:
                return 1;
            default:
                return 0;
        }
    }

    return 0;
}

int main(void) {
    const unsigned char program[] = {
        OP_LEN, 5,
        OP_LOAD, 0, OP_XOR, 0x20, OP_CMP, ('v' ^ 0x20),
        OP_LOAD, 1, OP_XOR, 0x20, OP_CMP, ('m' ^ 0x20),
        OP_LOAD, 2, OP_XOR, 0x20, OP_CMP, ('4' ^ 0x20),
        OP_LOAD, 3, OP_XOR, 0x20, OP_CMP, ('2' ^ 0x20),
        OP_LOAD, 4, OP_XOR, 0x20, OP_CMP, ('!' ^ 0x20),
        OP_HALT
    };
    char input[64];

    puts("== Crackme 19: Bytecode VM ==");
    printf("Bytecode input: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (run_vm(program, sizeof(program), input)) {
        puts("VM accepted input.");
        return 0;
    }

    puts("VM rejected input.");
    return 1;
}
