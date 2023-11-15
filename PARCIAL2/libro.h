#include <string.h>
#include <stdio.h>
#ifndef __LIBROH
#define __LIBROH

typedef struct
{
    char titulo [100];
    char autor1 [50];
    char autor2 [50];
    char autor3 [50];
    char pags [10];
    char edicion [10];
    char isbn [15];
    char editorial [50];
    char genero [50];
} Libro;

void mostrarLibro(Libro libro)
{
    printf("-------------------------\n");
    printf("Titulo: %s", libro.titulo);
    printf("\nAutor 1: %s", libro.autor1);
    if (strcmp(libro.autor2, "") != 0)
    {
        printf("\nAutor 2: %s", libro.autor2);
    }
    if (strcmp(libro.autor3, "") != 0)
    {
        printf("\nAutor 3: %s", libro.autor3);
    }
    printf("\nPaginas: %s", libro.pags);
    printf("\nEdicion: %s", libro.edicion);
    printf("\nISBN: %s", libro.isbn);
    printf("\nEditorial: %s", libro.editorial);
    printf("\nGenero: %s\n", libro.genero);
    printf("-------------------------\n");
}


char * getTitulo (Libro * libro)
{
    return libro -> titulo;
}

void setTitulo (Libro * libro, char titulo)
{
    strcpy (libro -> titulo, &titulo);
}

char * getAutor1 (Libro * libro)
{
    return libro -> autor1;
}

void setAutor1 (Libro * libro, char autor1)
{
    strcpy (libro -> autor1, &autor1);
}

char * getAutor2 (Libro * libro)
{
    return libro -> autor2;
}

void setAutor2 (Libro * libro, char autor2)
{
    strcpy (libro -> autor2, &autor2);
}

char * getAutor3 (Libro * libro)
{
    return libro -> autor3;
}

void setAutor3 (Libro * libro, char autor3)
{
    strcpy (libro -> autor3, &autor3);
}

char * getPags (Libro * libro)
{
    return libro -> pags;
}

void setPags (Libro * libro, char pags)
{
    strcpy (libro -> pags, &pags);
}

char * getEdicion (Libro * libro)
{
    return libro -> edicion;
}

void setEdicion (Libro * libro, char edicion)
{
    strcpy (libro -> edicion, &edicion);
}

char * getIsbn (Libro * libro)
{
    return libro -> isbn;
}

void setIsbn (Libro *libro, char isbn)
{
    strcpy (libro -> titulo, &isbn);
}

char * getEditorial (Libro * libro)
{
    return libro -> editorial;
}

void setEditorial (Libro * libro, char editorial)
{
    strcpy (libro -> editorial, &editorial);
}

char * getGenero (Libro * libro)
{
    return libro -> genero;
}

void setGenero (Libro * libro, char genero)
{
    strcpy (libro -> genero, &genero);
}

#endif

