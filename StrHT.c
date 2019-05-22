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

static void bail(void *p) {
    if (p == NULL)
        exit(0);
}

static char *strdup(char *s) {
    char *new;
    new = calloc(strlen(s)+1, 1);
    strcpy(new, s);
    bail(new);
    return new;
}

static int hFunc(char *str, int tSize) {

    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % tSize;
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

char *getStr(StrHT t, char *str) {

    int index = hFunc(str, t->tSize);
    entry* curr = &(t->table[index]);

    while (curr != NULL && strcmp(str, curr->str) != 0)
        curr = curr->next;

    char *final = NULL;
    if (curr != NULL)
        // found the string
        final = curr->str;

    return final;    
}

void  addVal(StrHT t, char *str, int val){ 

    int index = hFunc(str, t->tSize);
    entry* curr = &(t->table[index]);

    if (curr->str == NULL) {
        // empty list
        curr->str = strdup(str);
        curr->val = val;
    }else{
        while (strcmp(curr->str, str) != 0 && curr->next != NULL)
            // crawl through LL chain to last node, checking for duplicates along the way
            curr = curr->next;
        if (strcmp(curr->str, str) == 0)
            // string already in table
            return;
        
        entry *new = malloc(sizeof(entry));
        bail(new);
        curr->next = new;
        new->next = NULL;
        new->str = strdup(str);
        new->val = val;

    }
    t->nStr++;

}
int getVal(StrHT t, char *str){ 

    int index = hFunc(str, t->tSize);
    entry *curr = &(t->table[index]);

    while (curr != NULL && curr->str != NULL) {
        if (strcmp(curr->str, str) == 0)
            return curr->val;
        else
            curr = curr->next;
    }
    return NOT_PRESENT;
    
}
void  delVal(StrHT t, char *str){ 

    int index = hFunc(str, t->tSize);
    entry *curr = &(t->table[index]);
    
    if (strcmp(curr->str, str) == 0) {
        // entry to remove is first in list
        free(curr->str);
        curr->str = NULL;

        if (curr->next != NULL) 
            curr->next = curr->next->next;
        else
            // single item list
            curr->next = NULL;
    }
    entry *prev = curr;
    curr = curr->next;
    while (curr != NULL) {

        if (strcmp(curr->str, str) == 0) {
            prev->next = curr->next;
            free(curr->str);
            free(curr);
        }
        prev = curr;
        curr = curr->next;
    }
    t->nStr--;
}

void destroyStrHT(StrHT t){ 

    for (int i = 0; i < t->tSize; i++) {
        entry *curr = &(t->table[i]);

        if (curr->str != NULL) {
            free(curr->str);
            curr = curr->next;

            while (curr != NULL) {
                entry *next = curr->next;
                free(curr->str);
                free(curr);
                curr = next;
            }
        }
    }
    free(t->table);
    free(t);
}
