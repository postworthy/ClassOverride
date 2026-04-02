#include <stdint.h>
#include <stdio.h>
#include <string.h>

static uint32_t toy_hash(const char *input) {
    uint32_t acc = 0x13572468u;
    size_t i;

    for (i = 0; input[i] != '\0'; ++i) {
        acc = (acc << 5) | (acc >> 27);
        acc ^= (uint32_t)(unsigned char)input[i];
        acc += 0x21u + (uint32_t)i * 7u;
    }

    return acc;
}

int main(void) {
    char input[64];
    const uint32_t target = 0xe9327684u;

    puts("== Crackme 13: Custom Hash ==");
    printf("Input: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) != 8) {
        puts("Length check failed.");
        return 1;
    }

    if (toy_hash(input) == target) {
        puts("Hash matched.");
        return 0;
    }

    puts("Hash mismatch.");
    return 1;
}
