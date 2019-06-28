#include "urlParse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_URLS 10

urlCollection getURLs(char *html) {

    urlCollection u;
    u.num = 0;
    u.urls = calloc(sizeof(char*) * INITIAL_URLS, 1);
    u.arrLen = INITIAL_URLS;

    int length = strlen(html);

    int i = 0;
    while (i < length) {


        i++;
    }

    return u;
}
void destroyCollection(urlCollection c) {

    for (int i = 0; i < c.arrLen; i++) {
        free(c.urls[i]);
    }
    free(c.urls);
}