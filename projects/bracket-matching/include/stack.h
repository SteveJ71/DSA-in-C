\
#pragma once
#include <stddef.h>

typedef struct {
    char *items;
    size_t top;   // number of items currently on the stack
    size_t cap;   // allocated capacity
} CharStack;

int  stack_init(CharStack *s, size_t initial_cap);
void stack_free(CharStack *s);

int  stack_is_empty(const CharStack *s);
int  stack_push(CharStack *s, char ch);
int  stack_pop(CharStack *s, char *out);
