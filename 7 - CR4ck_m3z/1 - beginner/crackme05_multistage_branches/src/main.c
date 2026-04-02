#include <stdio.h>
#include <string.h>

static int validate(const char *input) {
    if (strlen(input) != 9) {
        puts("Stage 1 failed: wrong length.");
        return 0;
    }

    if (strncmp(input, "lab-", 4) != 0) {
        puts("Stage 2 failed: incorrect prefix.");
        return 0;
    }

    if (input[4] != '4' || input[5] != '2') {
        puts("Stage 3 failed: number pair mismatch.");
        return 0;
    }

    if (input[6] != '!') {
        puts("Stage 4 failed: punctuation mismatch.");
        return 0;
    }

    if (input[7] != 'R' || input[8] != 'E') {
        puts("Stage 5 failed: suffix mismatch.");
        return 0;
    }

    return 1;
}

int main(void) {
    char input[64];

    puts("== Crackme 05: Multistage Branches ==");
    printf("Challenge token: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (validate(input)) {
        puts("All stages passed.");
        return 0;
    }

    return 1;
}
