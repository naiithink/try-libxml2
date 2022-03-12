#include <iostream>
#include "aboutxml/anxml.h"

int
main (int argc, char **argv)
{
    if (argc == 1)
        return 1;
    
    MyXML foo (argv[1]);

    foo.fprintTree (stdout, 1);

    foo.closeDoc ();

    // This function is causing memory leak.
    // char *type;
    // fetchFile (argv[2], "out.txt", &type);
    // printf("%s\n", type);
    
    return 0;
}