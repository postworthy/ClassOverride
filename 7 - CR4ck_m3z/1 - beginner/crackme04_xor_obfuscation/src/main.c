#include <stdio.h>
#include <string.h>

static void decode_password(char *output, size_t size) {
    const unsigned char encoded[] = {0x33, 0x39, 0x3f, 0x2a, 0x33, 0x39, 0x31, 0x00};
    const unsigned char key = 0x5a;
    size_t i;

    if (size == 0) {
        return;
    }

    for (i = 0; i + 1 < size && encoded[i] != 0x00; ++i) {
        output[i] = (char)(encoded[i] ^ key);
    }

    output[i] = '\0';
}

int main(void) {
    char input[64];
    char expected[32];

    puts("== Crackme 04: XOR Obfuscation ==");
    printf("Passphrase: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';
    decode_password(expected, sizeof(expected));

    if (strcmp(input, expected) == 0) {
        puts("Access granted.");
        return 0;
    }

    puts("Access denied.");
    return 1;
}
