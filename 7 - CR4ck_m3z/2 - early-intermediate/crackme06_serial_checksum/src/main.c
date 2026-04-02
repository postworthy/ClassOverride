#include <ctype.h>
#include <stdio.h>
#include <string.h>

static int value_of(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }

    if (c >= 'A' && c <= 'Z') {
        return 10 + (c - 'A');
    }

    return -1;
}

static char char_of(int value) {
    if (value >= 0 && value <= 9) {
        return (char)('0' + value);
    }

    return (char)('A' + (value - 10));
}

static int validate_format(const char *serial) {
    size_t i;

    if (strlen(serial) != 14) {
        puts("Format error: serial must be 14 characters.");
        return 0;
    }

    if (serial[4] != '-' || serial[9] != '-') {
        puts("Format error: expected dashes at positions 5 and 10.");
        return 0;
    }

    for (i = 0; i < 14; ++i) {
        if (i == 4 || i == 9) {
            continue;
        }

        if (!isdigit((unsigned char)serial[i]) && !(serial[i] >= 'A' && serial[i] <= 'Z')) {
            puts("Format error: use uppercase letters and digits only.");
            return 0;
        }
    }

    return 1;
}

static int validate_checksum(const char *serial) {
    int g1[4];
    int g2[4];
    int i;
    int total = 0;

    for (i = 0; i < 4; ++i) {
        g1[i] = value_of(serial[i]);
        g2[i] = value_of(serial[i + 5]);
        total += g1[i] + g2[i];
    }

    if (serial[10] != char_of((g1[0] + g1[1] + g2[0]) % 36)) {
        puts("Checksum error: group 3 position 1 is wrong.");
        return 0;
    }

    if (serial[11] != char_of((g1[2] + g2[1] + g2[2]) % 36)) {
        puts("Checksum error: group 3 position 2 is wrong.");
        return 0;
    }

    if (serial[12] != char_of((g1[3] + g2[3] + 4) % 36)) {
        puts("Checksum error: group 3 position 3 is wrong.");
        return 0;
    }

    if (serial[13] != (char)('0' + (total % 10))) {
        puts("Checksum error: group 3 position 4 is wrong.");
        return 0;
    }

    return 1;
}

int main(void) {
    char serial[64];

    puts("== Crackme 06: Serial Checksum ==");
    printf("Enter serial: ");

    if (fgets(serial, sizeof(serial), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    serial[strcspn(serial, "\n")] = '\0';

    if (!validate_format(serial)) {
        return 1;
    }

    if (!validate_checksum(serial)) {
        return 1;
    }

    puts("Serial accepted.");
    return 0;
}
