\
#include <assert.h>
#include "bracket_matching.h"

int main(void) {
    assert(brackets_balanced("") == true);
    assert(brackets_balanced("abc") == true);
    assert(brackets_balanced("(({}))") == true);
    assert(brackets_balanced("([]{})") == true);
    assert(brackets_balanced("([)]") == false);
    assert(brackets_balanced("(") == false);
    assert(brackets_balanced(")") == false);
    assert(brackets_balanced("{[()]}") == true);
    assert(brackets_balanced("{[(])}") == false);

    return 0;
}
