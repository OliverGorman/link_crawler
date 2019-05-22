#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "StrHT.h"

int main(int argc, char *argv[]) {

    StrHT ht = newStrHT(100);
    assert(getPop(ht) == 0);
    assert(getVal(ht, "") == NOT_PRESENT);

    addVal(ht, "", 1);
    assert(getVal(ht, "") == 1);
    assert(getPop(ht) == 1);

    delVal(ht, "");
    assert(getVal(ht, "") == NOT_PRESENT);
    assert(getPop(ht) == 0);

    assert(getVal(ht, "abcdef") == NOT_PRESENT);

    addVal(ht, "abcdef", 1);
    assert(getVal(ht, "abcdef") == 1);

    delVal(ht, "abcdef");
    assert(getVal(ht, "abcdef") == NOT_PRESENT);

    addVal(ht, "abcdef", 1);
    assert(getVal(ht, "abcdef") == 1);
    addVal(ht, "123", 4);
    assert(getVal(ht, "123") == 4);
    addVal(ht, "uytrdv", 0);
    assert(getVal(ht, "uytrdv") == 0);
    assert(getPop(ht) == 3);
    char *s = getStr(ht, "uytrdv");
    assert(strcmp(s, "uytrdv") == 0);

    destroyStrHT(ht);
    return 0;
}