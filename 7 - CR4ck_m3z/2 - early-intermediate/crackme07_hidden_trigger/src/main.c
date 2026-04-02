#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int hidden_mode_enabled(int argc, char **argv) {
    const char *mode = getenv("CRACKME07_MODE");
    int i;

    if (mode != NULL && strcmp(mode, "staff") == 0) {
        return 1;
    }

    for (i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--staff") == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[64];
    int hidden = hidden_mode_enabled(argc, argv);

    puts("== Crackme 07: Hidden Trigger ==");
    printf("Password: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (hidden && strcmp(input, "guest") == 0) {
        puts("Alternate route accepted.");
        return 0;
    }

    if (strcmp(input, "opensesame") == 0) {
        puts("Primary route accepted.");
        return 0;
    }

    puts("Access denied.");
    return 1;
}
