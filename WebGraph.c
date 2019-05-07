#include "WebGraph.h"
#include "StrBank.h"
#include "StrHT.h"
#include "IntList.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _page {

    char *domain;   // points to a string in domains StrBank
    char *dir;      // is independently malloced
    IntList outlinks;   // reference indices in webGraph's pages[] array
    
}page;

typedef struct _webGraph {

    int nPages;
    int nLinks;
    page *pages;

    StrBank domains;    // contains pointers to malloced strings
    StrHT pageIndices;  // contains indices to pages[] corresponding to URLs

}webGraph;

WebGraph newGraph(int initCapacity){

    WebGraph newWG = malloc(sizeof(webGraph));
    if (newWG == NULL)
        return NULL;

    newWG->pages = malloc(sizeof(page)*initCapacity);

    newWG->domains = newStrBank(initCapacity);
    newWG->pageIndices = newStrHT(initCapacity);

    if (newWG->pages == NULL || newWG->domains == NULL || newWG->pageIndices == NULL)
        return NULL;

    return newWG;
}
void destroyGraph(WebGraph g){

    free(g);
}

int numPages(WebGraph g){

    return 0;
}
void addPage(WebGraph g, char *fullURL){

}
void addLink(WebGraph g, char *u, char *v){

}
int isPage(WebGraph g, char *fullURL){

    return 0;
}
int isLink(WebGraph g, char *u, char *v){

    return 0;
}