// Grabs the URLs in an HTML document
// matches the protocol and url in <a href="<url>"

typedef struct _urlCollection {
    int num;
    char **urls;
    int arrLen;
}urlCollection;

urlCollection getURLs(char *html);
void destroyCollection(urlCollection c);