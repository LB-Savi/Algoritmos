#include <stdio.h>
#include <string.h>
#include "libro.h"
#include "lista.h"
#include "utils.h"

int existeLibroIsbn (Biblioteca * biblioteca, const char * isbn) 
{
    primero(biblioteca);

    while (!esUltimo(biblioteca)) 
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp(libroActual.isbn, isbn) == 0) 
        {
            return 1; 
        }
        siguiente(biblioteca);
    }
    Libro libroActual = verActual(biblioteca);
    return strcmp(libroActual.isbn, isbn) == 0;
}

int existeLibroTitulo (Biblioteca * biblioteca, const char * titulo) 
{
    primero (biblioteca);
    while (!esUltimo (biblioteca)) 
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp (libroActual.titulo, titulo) == 0) 
        {
            return 1; 
        }
        siguiente(biblioteca);
    }
    Libro libroActual = verActual (biblioteca);
    if (strcmp (libroActual.titulo, titulo) == 0) 
    {
        return 1;
    }
    return 0;
}

int existeLibroGenero (Biblioteca * biblioteca, const char * genero)
{
    primero (biblioteca);
    while (!esUltimo (biblioteca)) 
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp (libroActual.genero, genero) == 0) 
        {
            return 1; 
        }
        siguiente(biblioteca);
    }
    Libro libroActual = verActual (biblioteca);
    if (strcmp (libroActual.genero, genero) == 0) 
    {
        return 1;
    }
    return 0;   
}

int existeLibroEditorial (Biblioteca * biblioteca, const char * editorial)
{
    primero (biblioteca);
    while (!esUltimo (biblioteca)) 
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp (libroActual.editorial, editorial) == 0) 
        {
            return 1; 
        }
        siguiente(biblioteca);
    }
    Libro libroActual = verActual (biblioteca);
    if (strcmp (libroActual.editorial, editorial) == 0) 
    {
        return 1;
    }
    return 0;   
}

int existeLibroEdicion (Biblioteca * biblioteca, const char * edicion)
{
    primero (biblioteca);
    while (!esUltimo (biblioteca)) 
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp (libroActual.edicion, edicion) == 0) 
        {
            return 1; 
        }
        siguiente(biblioteca);
    }
    Libro libroActual = verActual (biblioteca);
    if (strcmp (libroActual.edicion, edicion) == 0) 
    {
        return 1;
    }
    return 0;   
}

void crearLibro(Biblioteca *biblioteca, Libro *libro)
{
    do
    {
        leerCadena(libro->isbn, 20, "Ingrese el ISBN: ");
        // }while(existeLibroIsbn(biblioteca, libro->isbn) || strlen(libro->isbn) != 13);
    } while (existeLibroIsbn(biblioteca, libro->isbn));
    leerCadena(libro->titulo, 100, "Ingrese el tiulo: ");
    leerCadena(libro->autor1, 50, "Ingrese el autor 1: ");
    leerCadena(libro->autor2, 50, "Ingrese el autor 2 (enter para omitir): ");
    leerCadena(libro->autor3, 50, "Ingrese el autor 3 (enter para omitir): ");
    leerCadena(libro->pags, 10, "Ingrese la cantidad de paginas: ");
    leerCadena(libro->edicion, 10, "Ingrese el año de edicion: ");
    leerCadena(libro->editorial, 100, "Ingrese la editorial: ");
    leerCadena(libro->genero, 50, "Ingrese el genero: ");
}

void darDeAlta (Biblioteca *biblioteca)
{
    Libro libro;
    crearLibro (biblioteca, &libro);
    insertarDespues (biblioteca, libro);
    printf ("Libro dado de alta exitosamente.\n");
}

void darDeBaja (Biblioteca * biblioteca, const char *isbn)
{
    Nodo * aux = biblioteca -> com -> prox;
    Nodo * anterior = biblioteca -> com;
    while (aux != NULL)
    {
        if (strcmp (aux -> libro.isbn, isbn) == 0)
        {
            anterior -> prox = aux -> prox;
            free (aux);
            printf("Libro con ISBN %s eliminado de la biblioteca.\n", isbn);
            (biblioteca -> len)--;
            return;
        }
        anterior = aux;
        aux = aux -> prox;

    }
}

void modificar (Biblioteca * biblioteca, const char * isbn, int opcion)
{
    Nodo * aux = biblioteca -> com -> prox; 
    while (aux != NULL)
    {
        if (strcmp (aux -> libro.isbn, isbn) == 0)
        {
            char isbnLibroCopia[15];
            strcpy(isbnLibroCopia, aux->libro.isbn);
            if (opcion == 1)
            {
                leerCadena(aux->libro.titulo, 100, "Ingrese el nuevo título: ");
            }
            else if (opcion == 2)
            {
                leerCadena(aux->libro.autor1, 50, "Ingrese el nuevo autor 1: ");
            }
            else if (opcion == 3)
            {
                leerCadena(aux->libro.autor2, 50, "Ingrese el nuevo autor 2: ");
            }
            else if (opcion == 4)
            {
                leerCadena(aux->libro.autor3, 50, "Ingrese el nuevo autor 3: ");
            }
            else if (opcion == 5)
            {
                leerCadena(aux->libro.pags, 10, "Ingrese el nuevo numero de paginas: ");
            }
            else if (opcion == 6)
            {
                leerCadena(aux->libro.edicion, 10, "Ingrese el nuevo año de edicion: ");
            }
            else if (opcion == 7)
            {
                leerCadena(aux->libro.isbn, 15, "Ingrese el nuevo ISBN: ");
            }
            else if (opcion == 8)
            {
                leerCadena(aux->libro.editorial, 100, "Ingrese la nueva editorial: ");
            }
            else if (opcion == 9)
            {
                leerCadena(aux->libro.genero, 50, "Ingrese el nuevo genero: ");
            }

            printf("Libro con ISBN %s modificado.\n", isbnLibroCopia);
            return;
        }
        aux = aux->prox;
    }
}

void listarAutores(Biblioteca *biblioteca)
{
    char autores[500] = "\0";
    primero(biblioteca);
    siguiente (biblioteca);//
    while (1)//(!esUltimo(biblioteca))
    {
        Libro libroActual = verActual(biblioteca);
        if (strstr(autores, libroActual.autor1) == NULL)
        {
            strcat(autores, libroActual.autor1);
            strcat(autores, "\n");
        }
        if (strstr(autores, libroActual.autor2) == NULL)
        {
            strcat(autores, libroActual.autor2);
            strcat(autores, "\n");
        }
        if (strstr(autores, libroActual.autor3) == NULL)
        {
            strcat(autores, libroActual.autor3);
            strcat(autores, "\n");
        }
        if (esUltimo(biblioteca))//
        {
            break;
        }
        siguiente(biblioteca);
    }
    printf("Autores:\n %s", autores);
}

void listarLibros(Biblioteca *biblioteca)
{
    mostrarBiblioteca(*biblioteca); 
}

void listarLibrosPorGenero(Biblioteca *biblioteca, char *genero)
{
    primero(biblioteca);
    while (1)
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp(libroActual.genero, genero) == 0)
        {
            mostrarLibro(libroActual);
        }
        if (esUltimo(biblioteca))
        {
            break;
        }
        siguiente(biblioteca);
    }
}

void listarLibrosPorAutor(Biblioteca *biblioteca, char *autor)
{
    primero(biblioteca);
    while (1)
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp(libroActual.autor1, autor) == 0 || strcmp(libroActual.autor2, autor) == 0 || strcmp(libroActual.autor3, autor) == 0)
        {
            mostrarLibro(libroActual);
        }
        if (esUltimo(biblioteca))
        {
            break;
        }
        siguiente(biblioteca);
    }
}

void listarLibrosPorEditorial(Biblioteca *biblioteca, char *editorial)
{
    primero(biblioteca);
    while (1)
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp(libroActual.editorial, editorial) == 0)
        {
            mostrarLibro(libroActual); 
        }
        if (esUltimo(biblioteca))
        {
            break;
        }
        siguiente(biblioteca);
    }
}

void listarLibrosPorEditorialEntreAnios(Biblioteca *biblioteca, char *editorial, int anio1, int anio2)
{
    primero(biblioteca);
    while (1)
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp(libroActual.editorial, editorial) == 0 && atoi(libroActual.edicion) >= anio1 && atoi(libroActual.edicion) <= anio2)
        {
            mostrarLibro(libroActual); 
        }
        if (esUltimo(biblioteca))
        {
            break;
        }
        siguiente(biblioteca);
    }
}

void listarAutoresPorEditorial(Biblioteca *biblioteca, char *editorial)
{
    char autores[500] = "";
    primero(biblioteca);
    while (1)
    {
        Libro libroActual = verActual(biblioteca);
        if (strcmp(libroActual.editorial, editorial) == 0)
        {
            if (strstr(autores, libroActual.autor1) == NULL)
            {
                strcat(autores, libroActual.autor1);
                strcat(autores, "\n");
            }
            if (strstr(autores, libroActual.autor2) == NULL)
            {
                strcat(autores, libroActual.autor2);
                strcat(autores, "\n");
            }
            if (strstr(autores, libroActual.autor3) == NULL)
            {
                strcat(autores, libroActual.autor3);
                strcat(autores, "\n");
            }
        }
        if (esUltimo (biblioteca))
        {
            break;
        }
        siguiente(biblioteca);
    }
    printf("Autores:\n %s", autores);
}

void listarLibrosPorAnio(Biblioteca *biblioteca, char *anio)
{
    primero(biblioteca);
    while (1)
    {
        Libro libroActual = verActual(biblioteca);
        int aniolibro = atoi(libroActual.edicion);
        if (aniolibro == atoi(anio))
        {
            mostrarLibro(libroActual);
        }
        if (esUltimo(biblioteca))
        {
            break;
        }
        siguiente(biblioteca);
    }
}

void listarLibrosPorInicialAutor(Biblioteca *biblioteca, char *  inicial)
{
    char inicialCopia[2];
    char autor1Copia [100];
    char autor2Copia [100];
    char autor3Copia [100];
    inicialCopia[0] = *inicial;
    inicialCopia[1] = '\0';
    primero(biblioteca); 
    siguiente(biblioteca);
    while (1)
    {
        Libro libroActual = verActual (biblioteca);

        strcpy(autor1Copia, libroActual.autor1);
        char *nombre1 = strtok(autor1Copia, " ");
        char *apellido1 = strtok(NULL, " ");
        char inicialApellido1 [2];
        if (apellido1 != NULL)
        {
            inicialApellido1[0]=apellido1[0];
            inicialApellido1[1]='\0';
        }
        
        strcpy(autor2Copia, libroActual.autor2);
        char *nombre2 = strtok(autor2Copia, " ");
        char *apellido2 = strtok(NULL, " ");
        char inicialApellido2 [2];
        if (apellido2 != NULL)
        {
            inicialApellido2[0]=apellido2[0];
            inicialApellido2[1]='\0';
        }
        
        strcpy(autor3Copia, libroActual.autor3);
        char *nombre3 = strtok(autor3Copia, " ");
        char *apellido3 = strtok(NULL, " ");
        char inicialApellido3 [2];
        if (apellido3 != NULL)
        {
            inicialApellido3[0]=apellido3[0];
            inicialApellido3[1]='\0';
        }
        if(strcmp(inicialApellido1, inicialCopia) == 0 || strcmp(inicialApellido2, inicialCopia) == 0 || strcmp(inicialApellido3, inicialCopia) == 0)
        {
            mostrarLibro(libroActual);
        }
        if (esUltimo(biblioteca))
        {
            break;
        }
        siguiente(biblioteca);
        *inicialApellido1 = NULL;
        *inicialApellido2 = NULL;
        *inicialApellido3 = NULL;
    }
}

void listarLibrosPorPalabraTitulo(Biblioteca *biblioteca, char *palabra)
{
    primero(biblioteca);
    while (1)
    {
        Libro libroActual = verActual(biblioteca);
        if (strstr(libroActual.titulo, palabra) != NULL)
        {
            mostrarLibro(libroActual); 
        }
        if (esUltimo(biblioteca))
        {
            break;
        }
        siguiente(biblioteca);
    }
}
