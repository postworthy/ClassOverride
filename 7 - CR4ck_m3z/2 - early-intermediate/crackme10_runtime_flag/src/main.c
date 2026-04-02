#include <stdio.h>
#include <string.h>

static void build_flag(char *flag, size_t size) {
    const unsigned char part1[] = {0x75, 0x73, 0x62, 0x00};
    const unsigned char part2[] = {0x72, 0x74, 0x00};
    const unsigned char part3[] = {0x5e, 0x6c, 0x64, 0x00};
    size_t pos = 0;
    size_t i;

    if (size == 0) {
        return;
    }

    for (i = 0; i + 1 < size && part1[i] != 0x00; ++i) {
        flag[pos++] = (char)(part1[i] - 1);
    }

    for (i = 0; pos + 1 < size && part2[i] != 0x00; ++i) {
        flag[pos++] = (char)(part2[i] ^ 0x11);
    }

    for (i = 0; pos + 1 < size && part3[i] != 0x00; ++i) {
        flag[pos++] = (char)(part3[i] + 1);
    }

    flag[pos] = '\0';
}

int main(void) {
    char input[64];
    char expected[32];

    puts("== Crackme 10: Runtime Flag ==");
    printf("Enter flag: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("Input error.");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';
    build_flag(expected, sizeof(expected));

    if (strcmp(input, expected) == 0) {
        puts("Flag accepted.");
        return 0;
    }

    puts("Flag rejected.");
    return 1;
}
