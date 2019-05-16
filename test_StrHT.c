#include <assert.h>
#include "StrHT.h"

int main(int argc, char *argv[]) {

    StrHT ht = newStrHT(100);

    assert(getPop(ht) == 0);
    assert(getVal(ht, "") == -1);

    addVal(ht, "", 1);
    assert(getVal(ht, "") == 1);
    assert(getPop(ht) == 1);

    delVal(ht, "");
    assert(getVal(ht, "") == -1);
    assert(getPop(ht) == 0);

    assert(getVal(ht, "abcdef") == -1);

    addVal(ht, "abcdef", 1);
    assert(getVal(ht, "abcdef") == 1);

    delVal(ht, "abcdef");
    assert(getVal(ht, "abcdef") == -1);

    return 0;
}