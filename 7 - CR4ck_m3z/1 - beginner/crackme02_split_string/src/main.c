#include <stdio.h>
#include <string.h>

static void build_password(char *buffer, size_t size) {
    char part1[] = "shadow";
    char part2[] = "_st";
    char part3[] = "ack";

    if (size == 0) {
        return;
    }

    buffer[0] = '\0';
    strncat(buffer, part1, size - strlen(buffer) - 1);
    strncat(buffer, part2, size - strlen(buffer) - 1);
    strncat(buffer, part3, size - strlen(buffer) - 1);
}

int main(void) {
    char input[64];
    char expected[32];

    puts("== Crackme 02: Split String ==");
    printf("Password: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';
    build_password(expected, sizeof(expected));

    if (strcmp(input, expected) == 0) {
        puts("Correct.");
        return 0;
    }

    puts("Incorrect.");
    return 1;
}
