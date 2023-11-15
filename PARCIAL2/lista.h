#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libro.h"
#ifndef __LISTAH
#define __LISTAH

typedef struct nodo
{
    Libro libro;
    struct nodo *prox;
} Nodo;

typedef struct
{
    Nodo *com;
    Nodo *actual;
    int len;
} Biblioteca;

void crearBiblioteca(Biblioteca *l)
{
    Nodo *cen = (Nodo *)malloc(sizeof(Nodo));
    cen->prox = NULL;

    Nodo *cab = (Nodo *)malloc(sizeof(Nodo));
    cab->prox = cen;

    l->com = cab;
    l->actual = l->com;
    l->len = 0;
}

void primero(Biblioteca *l)
{
    l->actual = l->com->prox;
}

bool esUltimo (Biblioteca * l)
{
	return l->actual -> prox == NULL;
}

void siguiente(Biblioteca *l)
{
    l->actual = l->actual->prox;
}

void anterior(Biblioteca *l)
{
    Nodo *p = l->com;
    while (p->prox != l->actual)
    {
        p = p->prox;
    }
    l->actual = p;
}

int esBibliotecaVacia(Biblioteca *l)
{
    return l->len == 0;
}

Libro verActual(Biblioteca *l)
{
    return l->actual->libro;
}

void insertarDespues(Biblioteca *l, Libro x)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->libro = x;
    aux->prox = NULL;

    if (l->actual == NULL)
    {
        aux->prox = l->com->prox->prox;
        l->com->prox->prox = aux;
    } 
    else 
    {
        aux->prox = l->actual->prox;
        l->actual->prox = aux;
    }

    l->actual = aux;
    (l->len)++;
}

void insertarAntes(Biblioteca *l, Libro x)
{
    Libro datoAux = l->actual->libro;
    l->actual->libro = x;
    insertarDespues(l, datoAux);
}

void eliminarActual(Biblioteca *l)
{
    Nodo *aux = l->actual;
    anterior(l);
    l->actual->prox = aux->prox;
    free(aux);
    l->len--;
}

void mostrarBiblioteca(Biblioteca l)
{
    Nodo *aux = l.com->prox->prox; 
    
    while (aux != NULL)
    {
        mostrarLibro(aux->libro); //mostrarLibro(&aux->libro); 
        aux = aux->prox;
    }
}

#endif

