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

    return newWG;
}
void destroyGraph(WebGraph g){

    free(g->pages);
    destroyStrHT(g->urls);
    free(g);
}

int numPages(WebGraph g){

    return g->nPages;
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