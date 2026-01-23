#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "bracket_matching.h"

static void trim_newline(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) {
        s[n-1] = '\0';
        n--;
    }
}

int main(int argc, char **argv) {
    char buf[4096];

    const char *input = NULL;
    if (argc >= 2) {
        input = argv[1];
    } else {
        printf("Enter a line to check: ");
        if (!fgets(buf, sizeof(buf), stdin)) return 1;
        trim_newline(buf);
        input = buf;
    }

    if (brackets_balanced(input)) {
        printf("Balanced\n");
        return 0;
    } else {
        printf("Unbalanced\n");
        return 2;
    }
}
