#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void normalize_username(char *dest, size_t size, const char *src) {
    size_t i;

    if (size == 0) {
        return;
    }

    for (i = 0; i + 1 < size && src[i] != '\0'; ++i) {
        dest[i] = (char)toupper((unsigned char)src[i]);
    }

    dest[i] = '\0';
}

static void generate_key(char *dest, size_t size, const char *username) {
    unsigned int sum = 0x1234u;
    size_t len = strlen(username);
    size_t i;
    unsigned int part1;
    unsigned int part2;
    unsigned int part3;

    for (i = 0; username[i] != '\0'; ++i) {
        unsigned int ch = (unsigned int)(unsigned char)username[i];
        sum += ch * (unsigned int)(i + 1);
        sum ^= ch << (i % 4);
    }

    part1 = (sum ^ ((unsigned int)len * 0x55u)) & 0xffffu;
    part2 = (sum + (unsigned int)len * 17u) & 0xffu;
    part3 = ((unsigned int)len * (unsigned int)len + (unsigned int)(unsigned char)username[0]) & 0xffu;

    snprintf(dest, size, "%04X-%02X-%02X", part1, part2, part3);
}

int main(void) {
    char username_in[64];
    char username[64];
    char key_in[64];
    char expected[32];

    puts("== Crackme 08: Username to Key ==");
    printf("Username: ");

    if (fgets(username_in, sizeof(username_in), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    username_in[strcspn(username_in, "\n")] = '\0';

    if (username_in[0] == '\0') {
        puts("Username cannot be empty.");
        return 1;
    }

    normalize_username(username, sizeof(username), username_in);

    printf("Serial key: ");
    if (fgets(key_in, sizeof(key_in), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    key_in[strcspn(key_in, "\n")] = '\0';
    generate_key(expected, sizeof(expected), username);

    if (strcmp(key_in, expected) == 0) {
        puts("Key accepted.");
        return 0;
    }

    puts("Key rejected.");
    return 1;
}
