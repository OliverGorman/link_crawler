#include "WebGraph.h"
#include "StrHT.h"
#include "IntList.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _page {

    char *url;      // points to a string in StrHT "urls"
    IntList outlinks;   // reference indices in webGraph's pages[] array
    
}page;

typedef struct _webGraph {

    int nPages;
    int capacity;
    int nLinks;
    page *pages;

    StrHT urls;  // contains indices to pages[] corresponding to URLs

}webGraph;

WebGraph newGraph(int initCapacity){

    WebGraph newWG = malloc(sizeof(webGraph));
    if (newWG == NULL)
        return NULL;

    newWG->pages = malloc(sizeof(page)*initCapacity);
    if (newWG->pages == NULL)
        return NULL;

    newWG->urls = newStrHT(initCapacity);
    if (newWG->urls == NULL)
        return NULL;

    newWG->capacity = initCapacity;
    newWG->nPages = 0;
    newWG->nLinks = 0;
    return newWG;
}
void destroyGraph(WebGraph g){

    for (int i = 0; i < g->nPages; i++) {
        freeIntList(g->pages[i].outlinks);
    }
    free(g->pages);
    destroyStrHT(g->urls);
    free(g);
}

int numPages(WebGraph g){

    return g->nPages;
}
void addPage(WebGraph g, char *fullURL){

    if (g->nPages == g->capacity || getVal(g->urls, fullURL) != NOT_PRESENT)
        return;
    
    addVal(g->urls, fullURL, g->nPages);
    g->pages[g->nPages].outlinks = newIntList();
    g->pages[g->nPages].url = getStr(g->urls, fullURL);
    g->nPages++;
}
void addLink(WebGraph g, char *u, char *v){

    int uIn = getVal(g->urls, u);
    int vIn = getVal(g->urls, v);
    if (uIn == NOT_PRESENT || vIn == NOT_PRESENT || uIn == vIn)   // invalid names given / no self-links
        return;
    
    if (!IntListContains(g->pages[uIn].outlinks, vIn)) {
        // ignore parallel edges
        IntListInsert(g->pages[uIn].outlinks, vIn);
        g->nLinks++;
    }
}
int isPage(WebGraph g, char *fullURL){

    return getVal(g->urls, fullURL) == NOT_PRESENT ? 0 : 1;
}
int isLink(WebGraph g, char *u, char *v){

    int uIn = getVal(g->urls, u);
    int vIn = getVal(g->urls, v);
    if (uIn == NOT_PRESENT || vIn == NOT_PRESENT || uIn == vIn)   // invalid names given / no self-links
        return 0;
    
    return IntListContains(g->pages[uIn].outlinks, vIn) ? 1 : 0;
}