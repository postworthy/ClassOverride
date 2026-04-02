#include <stdio.h>
#include <string.h>

static void unpack_expected(char *dest, size_t size) {
    const unsigned char packed[] = {0x2f, 0x35, 0x28, 0x3e, 0x3d, 0x2a, 0x3f, 0x2e, 0x37};
    size_t i;

    if (size == 0) {
        return;
    }

    for (i = 0; i + 1 < size && i < sizeof(packed); ++i) {
        dest[i] = (char)((packed[i] ^ 0x5a) - (char)i);
    }

    dest[i] = '\0';
}

int main(void) {
    char input[64];
    char expected[32];

    puts("== Crackme 18: Runtime Unpack ==");
    printf("Packed token: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';
    unpack_expected(expected, sizeof(expected));

    if (strcmp(input, expected) == 0) {
        puts("Unpacked match.");
        return 0;
    }

    puts("Unpacked mismatch.");
    return 1;
}
