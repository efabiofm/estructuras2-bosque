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

#define BLACK   "\033[0m" 
#define RED     "\033[31m"

ArbolRN::ArbolRN() {
    raiz = NULL;
}

NodoRN* ArbolRN::insertarRecursivo(NodoRN *r, NodoRN *pt)
{
    if (r == NULL)
       return pt;
 
    if (pt->getDato() < r->getDato())
    {
        r->setIzquierdo(insertarRecursivo(r->getIzquierdo(), pt));
        r->getIzquierdo()->setPadre(r);
    }
    else if (pt->getDato() > r->getDato())
    {
        r->setDerecho(insertarRecursivo(r->getDerecho(), pt));
        r->getDerecho()->setPadre(r);
    }
    return r;
}

void ArbolRN::rotarIzquierda(NodoRN *r, NodoRN *pt)
{
    NodoRN *pt_derecho = pt->getDerecho();
 
    pt->setDerecho(pt_derecho->getIzquierdo());
 
    if (pt->getDerecho() != NULL)
        pt->getDerecho()->setPadre(pt);
 
    pt_derecho->setPadre(pt->getPadre());
 
    if (pt->getPadre() == NULL)
        r = pt_derecho;
 
    else if (pt == pt->getPadre()->getIzquierdo())
        pt->getPadre()->setIzquierdo(pt_derecho);
 
    else
        pt->getPadre()->setDerecho(pt_derecho);
 
    pt_derecho->setIzquierdo(pt);
    pt->setPadre(pt_derecho);
}
 
void ArbolRN::rotarDerecha(NodoRN *r, NodoRN *pt)
{
    NodoRN *pt_izquierdo = pt->getIzquierdo();
 
    pt->setIzquierdo(pt_izquierdo->getDerecho());
 
    if (pt->getIzquierdo() != NULL)
        pt->getIzquierdo()->setPadre(pt);
 
    pt_izquierdo->setPadre(pt->getPadre());
 
    if (pt->getPadre() == NULL)
        r = pt_izquierdo;
 
    else if (pt == pt->getPadre()->getIzquierdo())
        pt->getPadre()->setIzquierdo(pt_izquierdo);
 
    else
        pt->getPadre()->setDerecho(pt_izquierdo);
 
    pt_izquierdo->setDerecho(pt);
    pt->setPadre(pt_izquierdo);
}

void ArbolRN::equilibrar(NodoRN *r, NodoRN *pt)
{
    NodoRN *padre_pt = NULL;
    NodoRN *abuelo_pt = NULL;
 
    while ((pt != r) && (pt->getColor() != NEGRO) &&
           (pt->getPadre()->getColor() == ROJO))
    {
 
        padre_pt = pt->getPadre();
        abuelo_pt = pt->getPadre()->getPadre();
 
        /* Caso : A
           El padre de pt es hijo izquierdo del abuelo de pt */
        if (padre_pt == abuelo_pt->getIzquierdo())
        {
 
            NodoRN *tio_pt = abuelo_pt->getDerecho();
 
            /* Caso : 1
               El tío de pt es también rojo
               Solo se requiere recolorear */
            if (tio_pt != NULL && tio_pt->getColor() == ROJO)
            {
                abuelo_pt->setColor(ROJO);
                padre_pt->setColor(NEGRO);
                tio_pt->setColor(NEGRO);
                pt = abuelo_pt;
            }
 
            else
            {
                /* Caso : 2
                   pt es hijo derecho de su padre
                   Se requiere rotación a la izquierda */
                if (pt == padre_pt->getDerecho())
                {
                    rotarIzquierda(r, padre_pt);
                    pt = padre_pt;
                    padre_pt = pt->getPadre();
                }
 
                /* Caso : 3
                   pt es hijo izquierdo de su padre
                   Se requiere rotación a la derecha */
                rotarDerecha(r, abuelo_pt);
                bool colorAux = padre_pt->getColor();
                padre_pt->setColor(abuelo_pt->getColor());
                abuelo_pt->setColor(colorAux);
                pt = padre_pt;
            }
        }
 
        /* Caso : B
           El padre de pt es hijo derecho del abuelo de pt */
        else
        {
            NodoRN *tio_pt = abuelo_pt->getIzquierdo();
 
            /* Caso : 1
               Es tío de pt es también rojo
               Sólo se requiere recolorar */
            if ((tio_pt != NULL) && (tio_pt->getColor() == ROJO))
            {
                abuelo_pt->setColor(ROJO);
                padre_pt->setColor(NEGRO);
                tio_pt->setColor(NEGRO);
                pt = abuelo_pt;
            }
            else
            {
                /* Caso : 2
                   pt es hijo izquierdo de su padre
                   Se requiere rotación a la derecha */
                if (pt == padre_pt->getIzquierdo())
                {
                    rotarDerecha(r, padre_pt);
                    pt = padre_pt;
                    padre_pt = pt->getPadre();
                }
 
                /* Caso : 3
                   pt es hijo derecho de su padre
                   Se requiere rotación a la izquierda */
                rotarIzquierda(r, abuelo_pt);
                bool colorAux = padre_pt->getColor();
                padre_pt->setColor(abuelo_pt->getColor());
                abuelo_pt->setColor(colorAux);
                //swap(padre_pt->getColor(), abuelo_pt->getColor());
                pt = padre_pt;
            }
        }
    }
 
    r->setColor(NEGRO);
}

void ArbolRN::insertar(int pdato)
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
        r ? cout << (r->getColor()?BLACK:RED) << r->getDato() : cout << " ";
        for (int i = 0; i < espacios; i++) {
            cout << " ";
        }
        return;
    }
    if (nivel > 1) {
        imprimirRecursivo(r ? r->getIzquierdo() : NULL, nivel - 1, espacios);
        imprimirRecursivo(r ? r->getDerecho() : NULL, nivel - 1, espacios);
    }
}

int ArbolRN::getAltura(NodoRN *r) {
    if (!r) return 0;
    else {
        int izqAltura = getAltura(r->getIzquierdo());
        int derAltura = getAltura(r->getDerecho());
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