#include <stdio.h>
#include <string.h>

typedef enum {
    STATE_START = 0,
    STATE_F,
    STATE_S,
    STATE_M,
    STATE_DASH,
    STATE_2,
    STATE_20,
    STATE_202,
    STATE_ACCEPT,
    STATE_FAIL
} state_t;

static state_t step_state(state_t state, char ch) {
    switch (state) {
        case STATE_START:
            return ch == 'F' ? STATE_F : STATE_FAIL;
        case STATE_F:
            return ch == 'S' ? STATE_S : STATE_FAIL;
        case STATE_S:
            return ch == 'M' ? STATE_M : STATE_FAIL;
        case STATE_M:
            return ch == '-' ? STATE_DASH : STATE_FAIL;
        case STATE_DASH:
            return ch == '2' ? STATE_2 : STATE_FAIL;
        case STATE_2:
            return ch == '0' ? STATE_20 : STATE_FAIL;
        case STATE_20:
            return ch == '2' ? STATE_202 : STATE_FAIL;
        case STATE_202:
            return ch == '6' ? STATE_ACCEPT : STATE_FAIL;
        case STATE_ACCEPT:
        case STATE_FAIL:
        default:
            return STATE_FAIL;
    }
}

static int validate(const char *input) {
    state_t state = STATE_START;
    size_t i;

    for (i = 0; input[i] != '\0'; ++i) {
        state = step_state(state, input[i]);
        if (state == STATE_FAIL) {
            return 0;
        }
    }

    return state == STATE_ACCEPT;
}

int main(void) {
    char input[64];

    puts("== Crackme 15: State Machine ==");
    printf("Enter sequence: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (validate(input)) {
        puts("State accepted.");
        return 0;
    }

    puts("State rejected.");
    return 1;
}
