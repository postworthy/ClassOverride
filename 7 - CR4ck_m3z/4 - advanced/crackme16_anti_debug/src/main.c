#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>

static int debugger_present(void) {
    errno = 0;
    if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
        return 1;
    }

    return 0;
}

int main(void) {
    char input[64];

    puts("== Crackme 16: Anti-Debug ==");

    if (debugger_present()) {
        puts("Debugger detected.");
        return 1;
    }

    printf("Password: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "breakfree") == 0) {
        puts("Access granted.");
        return 0;
    }

    puts("Access denied.");
    return 1;
}
