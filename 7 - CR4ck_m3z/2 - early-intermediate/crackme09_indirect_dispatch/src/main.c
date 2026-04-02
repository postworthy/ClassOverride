#include <stdio.h>
#include <string.h>

typedef int (*validator_fn)(const char *);

static int check_length(const char *input) {
    return strlen(input) == 6;
}

static int check_prefix(const char *input) {
    return input[0] == 'J' && input[1] == 'M';
}

static int check_middle(const char *input) {
    return input[2] == 'P' && input[3] == '4';
}

static int check_suffix(const char *input) {
    return input[4] == '2' && input[5] == '!';
}

static int dispatch_validators(const char *input) {
    validator_fn validators[] = {
        check_length,
        check_prefix,
        check_middle,
        check_suffix
    };
    size_t i;

    for (i = 0; i < sizeof(validators) / sizeof(validators[0]); ++i) {
        if (!validators[i](input)) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    char input[64];

    puts("== Crackme 09: Indirect Dispatch ==");
    printf("Dispatch code: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (dispatch_validators(input)) {
        puts("Dispatch accepted.");
        return 0;
    }

    puts("Dispatch rejected.");
    return 1;
}
