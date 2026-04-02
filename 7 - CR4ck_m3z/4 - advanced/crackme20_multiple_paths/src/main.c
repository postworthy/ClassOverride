#include <stdio.h>
#include <string.h>

static int maintenance_mode(int argc, char **argv) {
    int i;

    for (i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--maintenance") == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[64];
    int alt_path = maintenance_mode(argc, argv);

    puts("== Crackme 20: Multiple Paths ==");
    printf("Access token: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "full_solve") == 0) {
        puts("Primary path accepted.");
        return 0;
    }

    if (alt_path && strcmp(input, "audit") == 0) {
        puts("Maintenance path accepted.");
        return 0;
    }

    puts("All paths denied.");
    return 1;
}
