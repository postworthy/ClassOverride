#include <stdio.h>
#include <string.h>

int main(void) {
    char input[64];
    const char *password = "swordfish";

    puts("== Crackme 01: Literal Password ==");
    printf("Enter password: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, password) == 0) {
        puts("Access granted.");
        return 0;
    }

    puts("Access denied.");
    return 1;
}
