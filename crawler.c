#include "WebGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

#ifdef SKIP_PEER_VERIFICATION
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif
 
#ifdef SKIP_HOSTNAME_VERIFICATION
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

typedef struct _htmlPage {
    char *raw;
    size_t size;
}htmlPage;

size_t write_pageData(char *contents, size_t size, size_t nmemb, void *userdata) {

    size_t bytes = size * nmemb;
    htmlPage *page = userdata;
    char *freshData = realloc(page->raw, page->size + bytes + 1);
    if (freshData == NULL) {
        printf("Not enough memory to download page!\n");
        return 0;
    }

    page->raw = freshData;
    memcpy(&(page->raw[page->size]), contents, bytes);
    page->size += bytes;
    page->raw[page->size] = '\0';
    return bytes;
}

int main(int argc, char *argv[]){

    CURL *curl;
    CURLcode res;

    htmlPage toDownload;
    toDownload.raw = malloc(1);
    toDownload.size = 0;
 
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_pageData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&toDownload);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    }

    res = curl_easy_perform(curl);

    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
 
    printf("%s\n", toDownload.raw);
    printf("Got %ld bytes\n", toDownload.size);

    /* always cleanup */ 
    curl_easy_cleanup(curl);
  
    curl_global_cleanup();

    return EXIT_SUCCESS;
}