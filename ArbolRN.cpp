/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolRN.cpp
 * Author: fabio
 * 
 * Created on June 25, 2017, 2:19 PM
 */

#include "ArbolRN.h"
#include <iostream>

using namespace std;

#define BLACK   "\033[30m" 
#define RED     "\033[31m"

ArbolRN::ArbolRN() {
    raiz = NULL;
}

NodoRN* ArbolRN::insertarRecursivo(NodoRN *&r, NodoRN *&pt)
{
    if (r == NULL)
       return pt;
 
    if (pt->dato < r->dato)
    {
        r->izquierdo  = insertarRecursivo(r->izquierdo, pt);
        r->izquierdo->padre = r;
    }
    else if (pt->dato > r->dato)
    {
        r->derecho = insertarRecursivo(r->derecho, pt);
        r->derecho->padre = r;
    }
    return r;
}

void ArbolRN::rotarIzquierda(NodoRN *&r, NodoRN *&pt)
{
    NodoRN *pt_derecho = pt->derecho;
 
    pt->derecho = pt_derecho->izquierdo;
 
    if (pt->derecho != NULL)
        pt->derecho->padre = pt;
 
    pt_derecho->padre = pt->padre;
 
    if (pt->padre == NULL)
        r = pt_derecho;
 
    else if (pt == pt->padre->izquierdo)
        pt->padre->izquierdo = pt_derecho;
 
    else
        pt->padre->derecho = pt_derecho;
 
    pt_derecho->izquierdo = pt;
    pt->padre = pt_derecho;
}
 
void ArbolRN::rotarDerecha(NodoRN *&r, NodoRN *&pt)
{
    NodoRN *pt_izquierdo = pt->izquierdo;
 
    pt->izquierdo = pt_izquierdo->derecho;
 
    if (pt->izquierdo != NULL)
        pt->izquierdo->padre = pt;
 
    pt_izquierdo->padre = pt->padre;
 
    if (pt->padre == NULL)
        r = pt_izquierdo;
 
    else if (pt == pt->padre->izquierdo)
        pt->padre->izquierdo = pt_izquierdo;
 
    else
        pt->padre->derecho = pt_izquierdo;
 
    pt_izquierdo->derecho = pt;
    pt->padre = pt_izquierdo;
}

void ArbolRN::equilibrar(NodoRN *&r, NodoRN *&pt)
{
    NodoRN *padre_pt = NULL;
    NodoRN *abuelo_pt = NULL;
 
    while ((pt != r) && (pt->color != NEGRO) &&
           (pt->padre->color == ROJO))
    {
 
        padre_pt = pt->padre;
        abuelo_pt = pt->padre->padre;
 
        /* Caso : A
           El padre de pt es hijo izquierdo del abuelo de pt */
        if (padre_pt == abuelo_pt->izquierdo)
        {
 
            NodoRN *tio_pt = abuelo_pt->derecho;
 
            /* Caso : 1
               El tío de pt es también rojo
               Solo se requiere recolorear */
            if (tio_pt != NULL && tio_pt->color == ROJO)
            {
                abuelo_pt->color = ROJO;
                padre_pt->color = NEGRO;
                tio_pt->color = NEGRO;
                pt = abuelo_pt;
            }
 
            else
            {
                /* Caso : 2
                   pt es hijo derecho de su padre
                   Se requiere rotación a la izquierda */
                if (pt == padre_pt->derecho)
                {
                    rotarIzquierda(r, padre_pt);
                    pt = padre_pt;
                    padre_pt = pt->padre;
                }
 
                /* Caso : 3
                   pt es hijo izquierdo de su padre
                   Se requiere rotación a la derecha */
                rotarDerecha(r, abuelo_pt);
                swap(padre_pt->color, abuelo_pt->color);
                pt = padre_pt;
            }
        }
 
        /* Caso : B
           El padre de pt es hijo derecho del abuelo de pt */
        else
        {
            NodoRN *tio_pt = abuelo_pt->izquierdo;
 
            /* Caso : 1
               Es tío de pt es también rojo
               Sólo se requiere recolorar */
            if ((tio_pt != NULL) && (tio_pt->color == ROJO))
            {
                abuelo_pt->color = ROJO;
                padre_pt->color = NEGRO;
                tio_pt->color = NEGRO;
                pt = abuelo_pt;
            }
            else
            {
                /* Caso : 2
                   pt es hijo izquierdo de su padre
                   Se requiere rotación a la derecha */
                if (pt == padre_pt->izquierdo)
                {
                    rotarDerecha(r, padre_pt);
                    pt = padre_pt;
                    padre_pt = pt->padre;
                }
 
                /* Caso : 3
                   pt es hijo derecho de su padre
                   Se requiere rotación a la izquierda */
                rotarIzquierda(r, abuelo_pt);
                swap(padre_pt->color, abuelo_pt->color);
                pt = padre_pt;
            }
        }
    }
 
    r->color = NEGRO;
}

void ArbolRN::insertar(int &pdato)
{
    NodoRN *pt = new NodoRN(pdato);
    raiz = insertarRecursivo(raiz, pt);
    equilibrar(raiz, pt);
}

void ArbolRN::imprimir() {
    if (!raiz) {
        cout << "Árbol vacío" << endl;
        return;
    }
    int h = getAltura(raiz);
    for (int i = 1; i <= h; i++) {
        int espaciosCentrales = getEspacios(i, h);
        int espaciosIniciales = (espaciosCentrales - 1) / 2;
        for (int i = 0; i < espaciosIniciales; i++) {
            cout << " ";
        }
        imprimirRecursivo(raiz, i, espaciosCentrales);
        cout << endl << endl;
    }
    cout << BLACK; /* Volver a poner la consola en negro */
}

void ArbolRN::imprimirRecursivo(NodoRN* r, int nivel, int espacios) {
    if (nivel == 1) {
        r ? cout << (r->color?BLACK:RED) << r->dato : cout << " ";
        for (int i = 0; i < espacios; i++) {
            cout << " ";
        }
        return;
    }
    if (nivel > 1) {
        imprimirRecursivo(r ? r->izquierdo : NULL, nivel - 1, espacios);
        imprimirRecursivo(r ? r->derecho : NULL, nivel - 1, espacios);
    }
}

int ArbolRN::getAltura(NodoRN *r) {
    if (!r) return 0;
    else {
        int izqAltura = getAltura(r->izquierdo);
        int derAltura = getAltura(r->derecho);
        return izqAltura > derAltura ? izqAltura + 1 : derAltura + 1;
    }
}

int ArbolRN::getEspacios(int nivel, int altura) {
    int cant = 1;
    for (int i = nivel; i < altura; i++) {
        cant = 2 * cant + 1;
    }
    return cant;
}