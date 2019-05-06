#ifndef WEBGRAPH_H
#define WEBGRAPH_H

#define TRUE 1
#define FALSE 0

typedef struct _webGraph *WebGraph;

WebGraph newGraph(int initCapacity);
void destroyGraph(WebGraph g);

int numPages(WebGraph g);
void addPage(WebGraph g, char *fullURL);
void addLink(WebGraph g, char *u, char *v);
int isPage(WebGraph g, char *fullURL);
int isLink(WebGraph g, char *u, char *v);

#endif