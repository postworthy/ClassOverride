#include <stdio.h>
#include <string.h>

static int validate(const char *input) {
    return strcmp(input, "letmein") == 0;
}

int main(void) {
    char input[64];
    int passed;

    puts("== Crackme 14: Patch Me ==");
    printf("Enter password: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';
    passed = validate(input);

    if (!passed) {
        puts("Nope.");
        return 1;
    }

    puts("Welcome.");
    return 0;
}
