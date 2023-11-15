#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "lista.h"
#include "biblioteca.h"

int menu ()
{
    int opcion;
    printf ("1. Alta\n");
    printf ("2. Baja\n");
    printf ("3. Modificacion\n");
    printf ("4. Buscar por titulo\n");
    printf ("5. Listados\n");
    printf ("6. Salir\n");
    printf ("Ingrese una opcion:\n");
    scanf ("%d", &opcion);
    return opcion;
}

int menuListados()
{
    int opcion;
    printf("0. Volver\n");
    printf("1. Listar todos los autores esistentes\n");
    printf("2. Listar todos los libros existentes\n");
    printf("3. Listar libros de un autor\n");
    printf("4. Listar libros de un genero\n");
    printf("5. Listar libros de una editorial\n");
    printf("6. Listar libros de una editorial en un rango de año de edicion\n");
    printf("7. Listar todos los autores de una editorial\n");
    printf("8. Listar libros de un año de edicion\n");
    printf("9. Listar libros de autores cuyos apellidos comienzan con una letra determinada\n");
    printf("10. Listar libros cuyos titulos contengan una palabra determinada\n");
    printf("Ingrese una opcion:\n");
    scanf("%d", &opcion);
    return opcion;
}

int menuModificar()
{
    int opcion;
    printf("0. Volver\n");
    printf("1. Titulo\n");
    printf("2. Autor 1\n");
    printf("3. Autor 2\n");
    printf("4. Autor 3\n");
    printf("5. Paginas\n");
    printf("6. Edicion\n");
    printf("7. ISBN\n");
    printf("8. Editorial\n");
    printf("9. Genero\n");
    printf("Ingrese una opcion:\n");
    scanf("%d", &opcion);
    return opcion;
}

int main() 
{
    Biblioteca biblioteca;
    crearBiblioteca(&biblioteca);
    int opcion = menu();
    system("cls"); 
    while (opcion != 6) 
    {
        if (opcion == 1) 
        {
            darDeAlta(&biblioteca);  
        } 
        else if (opcion == 2) 
        {
            char isbn[15];
            leerCadena(isbn, 15, "Ingrese el ISBN del libro a eliminar: ");
            if (existeLibroIsbn(&biblioteca, isbn))
            {
                darDeBaja(&biblioteca, isbn);
            }
            else
            {
                printf("No existe libro con el ISBN %s\n", isbn);
            }
        } 
        else if (opcion == 3) 
        {
            char isbn[15];
            leerCadena(isbn, 15, "Ingrese el ISBN del libro a modificar: ");
            if (existeLibroIsbn(&biblioteca, isbn))
            {
                int opcionModificar = menuModificar();
                while (opcionModificar != 0) 
                {
                    if (opcionModificar >= 1 && opcionModificar <= 9)
                    {
                        modificar(&biblioteca, isbn, opcionModificar);
                    }
                    else
                    {
                        printf("Opcion incorrecta.\n");
                    }
                    opcionModificar = menuModificar();
                    system("cls");
                }
            }
            else
            {
                printf("No existe libro con el ISBN %s\n", isbn);
            } 
        }    
        else if (opcion == 4) 
        {
            char titulo[100];
            leerCadena(titulo, 100, "Ingrese el titulo del libro a buscar: ");
            if (existeLibroTitulo(&biblioteca, titulo)) 
            {
                Libro libro = verActual(&biblioteca);
                mostrarLibro(libro);
            } 
            else 
            {
                printf("No existe ningun libro con el titulo %s\n", titulo);
            }
        } 
        else if (opcion == 5) 
        {
            int opcionListado = menuListados();
            while (opcionListado != 0) 
            {
                if (opcionListado == 1)
                {
                    listarAutores(&biblioteca);
                } 
                else if (opcionListado == 2) 
                {
                    if (!esBibliotecaVacia(&biblioteca)) 
                    {
                        mostrarBiblioteca(biblioteca);
                    } 
                    else 
                    {
                        printf("La biblioteca esta vacia.\n");
                    }
                } 
                else if (opcionListado == 3) 
                {
                    char autor[50];
                    leerCadena(autor, 50, "Ingrese el autor a buscar: ");
                    listarLibrosPorAutor(&biblioteca, autor);
                } 
                else if (opcionListado == 4) // Listar libros de un genero
                {
                    char genero[50];
                    leerCadena(genero, 50, "Ingrese el genero a buscar: ");
                    if (existeLibroGenero(&biblioteca, genero)) 
                    {
                        listarLibrosPorGenero (&biblioteca, genero);
                    } 
                    else 
                    {
                        printf("No existe ningun libro con el genero %s\n", genero);
                    }
                } 
                else if (opcionListado == 5) 
                {
                    char editorial[100];
                    leerCadena(editorial, 100, "Ingrese la editorial a buscar: ");
                    if (existeLibroEditorial(&biblioteca, editorial)) 
                    {
                        listarLibrosPorEditorial(&biblioteca, editorial);
                    } 
                    else 
                    {
                        printf("No existe ningun libro de la editorial %s\n", editorial);
                    }
                } 
                else if (opcionListado == 6) 
                {
                    char editorial[50];
                    char anio1[10], anio2[10];
                    leerCadena(editorial, 50, "Ingrese la editorial del libro a buscar: ");
                    if (existeLibroEditorial(&biblioteca, editorial)) 
                    {
                       leerCadena(anio1, 10, "Ingrese el año de inicio: ");
                       leerCadena(anio2, 10, "Ingrese el año de fin: "); 
                       listarLibrosPorEditorialEntreAnios(&biblioteca, editorial, atoi(anio1), atoi(anio2));
                    }
                    else
                    {
                        printf("No existe ningun libro de la editorial %s\n", editorial);
                    }    
                } 
                else if (opcionListado == 7) 
                {
                    char editorial[50];
                    leerCadena(editorial, 50, "Ingrese la editorial a buscar: ");
                    if (existeLibroEditorial (&biblioteca, editorial))
                    {
                        listarAutoresPorEditorial(&biblioteca, editorial);
                    }
                    else
                    {
                        printf("No existe ningun libro de la editorial %s\n", editorial);
                    }   
                } 
                else if (opcionListado == 8) 
                {
                    char edicion[10];
                    leerCadena(edicion, 10, "Ingrese el año de edicion a buscar: ");
                    if (existeLibroEdicion(&biblioteca, edicion)) 
                    {
                        listarLibrosPorAnio(&biblioteca, edicion);
                    } 
                    else 
                    {
                       printf("No existe ningun libro del año de edicion %s\n", edicion);
                    }
                } 
                else if (opcionListado == 9) 
                {
                    char inicial[5];
                    leerCadena(inicial,5,"Ingrese la inicial del apellido del autor a buscar: ");
                    listarLibrosPorInicialAutor(&biblioteca, inicial);
                } 
                else if (opcionListado == 10) 
                {
                    char palabra[50];
                    leerCadena(palabra, 50, "Ingrese una palabra del titulo del libro a buscar: ");
                    listarLibrosPorPalabraTitulo(&biblioteca, palabra);
                } 
                else 
                {
                    printf("Opcion incorrecta.\n");
                }
                opcionListado = menuListados();
                system("cls");
            }
        } 
        else
        {
            printf("Opcion incorrecta.\n");
        }
        opcion = menu();
        system("cls");
    }
    return 0;
}

