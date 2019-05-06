#include "WebGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _webGraph {

    int nPages;
    int nLinks;

}webGraph;

WebGraph newGraph(int initCapacity){

    WebGraph newWG = malloc(sizeof(webGraph));

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