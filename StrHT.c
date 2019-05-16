#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StrHT.h"

typedef struct _entry{

    char *str;
    int val;
    struct _entry *next;
}entry;

typedef struct _strHT{

    entry *table;
    int nStr;
    int tSize;
}strHT;

static int hFunc(char *str, int tSize) {
    return 0;
}

StrHT newStrHT(int size) {

    StrHT new = malloc(sizeof(strHT));
    if (new == NULL)
        return NULL;
    
    new->table = calloc(size, sizeof(entry));
    if (new->table == NULL)
        return NULL;

    new->nStr = 0;
    new->tSize = size;
    return new;
}

int getPop(StrHT t) {
    return t->nStr;
}

void  addVal(StrHT t, char *str, int val){ 

    int index = hFunc(str, t->tSize);
    entry* curr = &(t->table[index]);

    // crawl through LL chain to end
    while (curr->next != NULL)
        curr = curr->next;
    
    curr->str = malloc(strlen(str));
    strcpy(curr->str, str);
    curr->val = val;

}
int getVal(StrHT t, char *str){ 

    int index = hFunc(str, t->tSize);
    entry *curr = &(t->table[index]);

    while (curr != NULL) {
        if (strcmp(curr->str, str) != 0)
            return curr->val;
        else
            curr = curr->next;
    }
    
}
void  delVal(StrHT t, char *str){ 

}

void destroyStrHT(StrHT t){ 

}
