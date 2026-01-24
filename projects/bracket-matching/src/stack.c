
#include "stack.h"
#include <stdlib.h>

int stack_init(CharStack *s, size_t initial_cap) {
    if (!s) return 0;
    if (initial_cap == 0) initial_cap = 16;

    s->items = (char*)malloc(initial_cap * sizeof(char));
    if (!s->items) {
        s->top = 0;
        s->cap = 0;
        return 0;
    }
    s->top = 0;
    s->cap = initial_cap;
    return 1;
}

void stack_free(CharStack *s) {
    if (!s) return;
    free(s->items);
    s->items = NULL;
    s->top = 0;
    s->cap = 0;
}

int stack_is_empty(const CharStack *s) {
    return (!s || s->top == 0);
}

static int stack_grow(CharStack *s) {
    size_t new_cap = (s->cap == 0) ? 16 : (s->cap * 2);
    char *p = (char*)realloc(s->items, new_cap * sizeof(char));
    if (!p) return 0;
    s->items = p;
    s->cap = new_cap;
    return 1;
}

int stack_push(CharStack *s, char ch) {
    if (!s) return 0;
    if (s->top >= s->cap) {
        if (!stack_grow(s)) return 0;
    }
    s->items[s->top++] = ch;
    return 1;
}

int stack_pop(CharStack *s, char *out) {
    if (!s || s->top == 0) return 0;
    s->top--;
    if (out) *out = s->items[s->top];
    return 1;
}
