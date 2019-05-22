#include <assert.h>
#include <stdlib.h>
#include "WebGraph.h"

int main(int argc, char *argv[]) {

    WebGraph wg = newGraph(100);

    addPage(wg, "big page");
    addPage(wg, "ghjk");
    addPage(wg, "nnnn");
    addPage(wg, "nnnn");

    assert(numPages(wg) == 3);

    addLink(wg, "big page", "nnnn");
    assert(isLink(wg, "big page", "nnnn"));

    assert(!isPage(wg, ""));
    assert(isPage(wg, "nnnn"));

    assert(!isLink(wg, "nnnn", "big page"));

    destroyGraph(wg);
    return EXIT_SUCCESS;
}