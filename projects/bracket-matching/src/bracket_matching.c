
#include "bracket_matching.h"
#include "stack.h"

static int is_open(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

static int is_close(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

static int matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool brackets_balanced(const char *s) {
    if (!s) return true;

    CharStack st;
    if (!stack_init(&st, 32)) return false;

    for (const char *p = s; *p; ++p) {
        char ch = *p;

        if (is_open(ch)) {
            if (!stack_push(&st, ch)) { stack_free(&st); return false; }
        } else if (is_close(ch)) {
            char open = 0;
            if (!stack_pop(&st, &open) || !matches(open, ch)) {
                stack_free(&st);
                return false;
            }
        }
    }

    int ok = stack_is_empty(&st);
    stack_free(&st);
    return ok ? true : false;
}
