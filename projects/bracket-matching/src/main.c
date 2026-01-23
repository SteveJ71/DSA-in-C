#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "bracket_matching.h"

static void trim_newline(char* s)
{
    if (!s) return;
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[n - 1] = '\0';
        n--;
    }
}

int main(void)
{
    const char* path = "text.txt";
    FILE* fp = fopen(path, "r");
    if (!fp) {
        printf("Error: could not open '%s'\n", path);
        printf("Tip: put text.txt in the folder you run build.bat from.\n");
        return 1;
    }

    char buf[4096];
    int lineNo = 0;
    int anyUnbalanced = 0;

    while (fgets(buf, sizeof(buf), fp)) {
        lineNo++;
        trim_newline(buf);

        // Optional: skip empty lines
        if (buf[0] == '\0')
            continue;

        int ok = brackets_balanced(buf) ? 1 : 0;
        printf("Line %d: %s | %s\n", lineNo, ok ? "Balanced" : "Unbalanced", buf);

        if (!ok) anyUnbalanced = 1;
    }

    fclose(fp);

    // Return code: 0 if all balanced, 2 if any unbalanced (handy for scripting)
    return anyUnbalanced ? 2 : 0;
}
