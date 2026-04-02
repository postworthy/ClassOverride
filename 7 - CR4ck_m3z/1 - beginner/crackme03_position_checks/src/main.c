#include <stdio.h>
#include <string.h>

static int validate(const char *input) {
    if (strlen(input) != 8) {
        return 0;
    }

    if (input[0] != 'R') {
        return 0;
    }

    if (input[1] != '3') {
        return 0;
    }

    if (input[2] != 'v') {
        return 0;
    }

    if (input[3] != '_') {
        return 0;
    }

    if (input[4] + 1 != input[5]) {
        return 0;
    }

    if (input[4] != 'm') {
        return 0;
    }

    if (input[6] != '!') {
        return 0;
    }

    if (input[7] != '?') {
        return 0;
    }

    return 1;
}

int main(void) {
    char input[64];

    puts("== Crackme 03: Position Checks ==");
    printf("Code: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (validate(input)) {
        puts("Unlocked.");
        return 0;
    }

    puts("Locked.");
    return 1;
}
