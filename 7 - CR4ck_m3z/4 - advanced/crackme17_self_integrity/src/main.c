#include <stdio.h>
#include <string.h>

static unsigned int checksum_region(void) {
    const unsigned char region[] = {0x13, 0x37, 0xc0, 0xde, 0x42, 0x7a};
    unsigned int checksum = 0;
    size_t i;

    for (i = 0; i < sizeof(region); ++i) {
        checksum += (unsigned int)region[i] * (unsigned int)(i + 1);
    }

    return checksum;
}

int main(void) {
    char input[64];
    const unsigned int expected_checksum = 0x0a5fu;

    puts("== Crackme 17: Self-Integrity ==");

    if (checksum_region() != expected_checksum) {
        puts("Integrity check failed.");
        return 1;
    }

    printf("Token: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "integrity") == 0) {
        puts("Token accepted.");
        return 0;
    }

    puts("Token rejected.");
    return 1;
}
