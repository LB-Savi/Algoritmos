#include <stdio.h>
#include <string.h>

#ifndef __UTILSH
#define __UTILSH

char * leerCadena(char * c, int n, char * msg)
{
    fflush (stdin);
    printf ("%s", msg);
    fgets (c, n, stdin);
    c [strlen(c) - 1] = '\0';
    return c;
}

#endif
