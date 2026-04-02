#include <stdio.h>
#include <string.h>

static void decode_xor(char *dest, size_t size, const unsigned char *src, size_t len, unsigned char key) {
    size_t i;

    if (size == 0) {
        return;
    }

    for (i = 0; i + 1 < size && i < len; ++i) {
        dest[i] = (char)(src[i] ^ key);
    }

    dest[i] = '\0';
}

int main(void) {
    const unsigned char prompt_data[] = {0x76, 0x4d, 0x49, 0x47, 0x4c, 0x18, 0x02};
    const unsigned char secret_data[] = {0x51, 0x4b, 0x4e, 0x47, 0x4c, 0x56, 0x7d, 0x51, 0x56, 0x47, 0x52};
    char prompt[16];
    char expected[32];
    char input[64];

    decode_xor(prompt, sizeof(prompt), prompt_data, sizeof(prompt_data), 0x22);
    decode_xor(expected, sizeof(expected), secret_data, sizeof(secret_data), 0x22);

    puts("== Crackme 11: Anti-Strings ==");
    printf("%s", prompt);

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, expected) == 0) {
        puts("Accepted.");
        return 0;
    }

    puts("Rejected.");
    return 1;
}
