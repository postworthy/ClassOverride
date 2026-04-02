#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void normalize_case(char *dest, size_t size, const char *src) {
    size_t i;

    if (size == 0) {
        return;
    }

    for (i = 0; i + 1 < size && src[i] != '\0'; ++i) {
        dest[i] = (char)tolower((unsigned char)src[i]);
    }

    dest[i] = '\0';
}

static int check_length(const char *input) {
    return strlen(input) == 9;
}

static int check_prefix(const char *input) {
    return strncmp(input, "call", 4) == 0;
}

static int check_suffix(const char *input) {
    return strcmp(input + 4, "graph") == 0;
}

static int check_weight(const char *input) {
    unsigned int total = 0;
    size_t i;

    for (i = 0; input[i] != '\0'; ++i) {
        total += (unsigned int)(unsigned char)input[i] * (unsigned int)(i + 1);
    }

    return total == 4759u;
}

static int validate(const char *input) {
    char normalized[32];

    normalize_case(normalized, sizeof(normalized), input);

    if (!check_length(normalized)) {
        return 0;
    }

    if (!check_prefix(normalized)) {
        return 0;
    }

    if (!check_suffix(normalized)) {
        return 0;
    }

    return check_weight(normalized);
}

int main(void) {
    char input[64];

    puts("== Crackme 12: Multi-Function Validator ==");
    printf("Enter phrase: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (validate(input)) {
        puts("Validated.");
        return 0;
    }

    puts("Validation failed.");
    return 1;
}
