/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolAVL.cpp
 * Author: fabio
 * 
 * Created on June 23, 2017, 11:02 PM
 */

#include <iostream>
#include "ArbolAVL.h"
#include "NodoAVL.h"

ArbolAVL::ArbolAVL() {
    raiz = NULL;
}

ArbolAVL::~ArbolAVL() {
}

void ArbolAVL::insertar(const int dato) {
    NodoAVL *padre = NULL;
    NodoAVL *aux = raiz;
    // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
    while (aux && dato != aux->getDato()) {
        padre = aux;
        if (dato > aux->getDato()) aux = aux->getDerecho();
        else if (dato < aux->getDato()) aux = aux->getIzquierdo();
    }
    // Si se ha encontrado el elemento, regresar sin insertar
    if (aux) return;
    // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será el nodo raiz
    if (!padre) raiz = new NodoAVL(dato);
    // Si el dato es menor que el que contiene el nodo padre, lo insertamos en la rama izquierda
    else if (dato < padre->getDato()) {
        padre->setIzquierdo(new NodoAVL(dato, padre));
        equilibrar(padre, -1, true);
    }
    // Si el dato es mayor que el que contiene el nodo padre, lo insertamos en la rama derecha
    else if (dato > padre->getDato()) {
        padre->setDerecho(new NodoAVL(dato, padre));
        equilibrar(padre, 1, true);
    }
}

bool ArbolAVL::esHoja(NodoAVL * nodo) {
    return !nodo->getIzquierdo() && !nodo->getDerecho();
}

void ArbolAVL::equilibrar(NodoAVL * nodo, int rama, bool nuevo) {
    bool salir = false;
    while (nodo && !salir) {
        if (nuevo)
            if (rama == -1) nodo->setFE(nodo->getFE() - 1);
            else nodo->setFE(nodo->getFE() + 1);
        else
            if (rama == -1) nodo->setFE(nodo->getFE() + 1);
        else nodo->setFE(nodo->getFE() - 1);
        if (nodo->getFE() == 0) salir = true;
        else if (nodo->getFE() == -2) {
            if (nodo->getIzquierdo()->getFE() == 1) rdd(nodo);
            else rsd(nodo);
            salir = true;
        } else if (nodo->getFE() == 2) {
            if (nodo->getDerecho()->getFE() == -1) rdi(nodo);
            else rsi(nodo);
            salir = true;
        }
        if (nodo->getPadre())
            if (nodo->getPadre()->getDerecho() == nodo) rama = 1;
            else rama = -1;
        nodo = nodo->getPadre();
    }
}

void ArbolAVL::rsd(NodoAVL * nodo) {
    NodoAVL *Padre = nodo->getPadre();
    NodoAVL *P = nodo;
    NodoAVL *Q = P->getIzquierdo();
    NodoAVL *B = Q->getDerecho();

    if (Padre)
        if (Padre->getDerecho() == P) Padre->setDerecho(Q);
        else Padre->setIzquierdo(Q);
    else raiz = Q;

    // Reconstruir árbol:
    P->setIzquierdo(B);
    Q->setDerecho(P);

    // Reasignar padres:
    P->setPadre(Q);
    if (B) B->setPadre(P);
    Q->setPadre(Padre);

    // Ajustar valores de FE:
    P->setFE(0);
    Q->setFE(0);
}

void ArbolAVL::rsi(NodoAVL * nodo) {
NodoAVL *Padre = nodo->getPadre();
    NodoAVL *P = nodo;
    NodoAVL *Q = P->getDerecho();
    NodoAVL *B = Q->getIzquierdo();

    if (Padre)
        if (Padre->getDerecho() == P) Padre->setDerecho(Q);
        else Padre->setIzquierdo(Q);
    else raiz = Q;

    // Reconstruir árbol:
    P->setDerecho(B);
    Q->setIzquierdo(P);

    // Reasignar padres:
    P->setPadre(Q);
    if (B) B->setPadre(P);
    Q->setPadre(Padre);

    // Ajustar valores de FE:
    P->setFE(0);
    Q->setFE(0);
}

void ArbolAVL::rdd(NodoAVL * nodo) {
    NodoAVL *Padre = nodo->getPadre();
    NodoAVL *P = nodo;
    NodoAVL *Q = P->getIzquierdo();
    NodoAVL *R = Q->getDerecho();
    NodoAVL *B = R->getIzquierdo();
    NodoAVL *C = R->getDerecho();

    if (Padre)
        if (Padre->getDerecho() == nodo) Padre->setDerecho(R);
        else Padre->setIzquierdo(R);
    else raiz = R;

    // Reconstruir árbol:
    Q->setDerecho(B);   
    P->setIzquierdo(C);
    R->setIzquierdo(Q);
    R->setDerecho(P);

    // Reasignar padres:
    R->setPadre(Padre);
    Q->setPadre(R);
    P->setPadre(Q);
    if (B) B->setPadre(P);
    if (C) C->setPadre(Q);

    // Ajustar valores de FE:
    switch (R->getFE()) {
        case -1: P->setFE(1);
            Q->setFE(0);
            break;
        case 0: P->setFE(0);
            Q->setFE(0);
            break;
        case 1: P->setFE(0);
            Q->setFE(-1);
            break;
    }
    R->setFE(0);
}

void ArbolAVL::rdi(NodoAVL * nodo) {
    NodoAVL *Padre = nodo->getPadre();
    NodoAVL *P = nodo;
    NodoAVL *Q = P->getDerecho();
    NodoAVL *R = Q->getIzquierdo();
    NodoAVL *B = R->getIzquierdo();
    NodoAVL *C = R->getDerecho();

    if (Padre)
        if (Padre->getDerecho() == nodo) Padre->setDerecho(R);
        else Padre->setIzquierdo(R);
    else raiz = R;

    // Reconstruir árbol:
    P->setDerecho(B);
    Q->setIzquierdo(C);
    R->setIzquierdo(P);
    R->setDerecho(Q);

    // Reasignar padres:
    R->setPadre(Padre);
    Q->setPadre(R);
    P->setPadre(Q);
    if (B) B->setPadre(P);
    if (C) C->setPadre(Q);

    // Ajustar valores de FE:
    switch (R->getFE()) {
        case -1: P->setFE(0);
            Q->setFE(1);
            break;
        case 0: P->setFE(0);
            Q->setFE(0);
            break;
        case 1: P->setFE(-1);
            Q->setFE(0);
            break;
    }
    R->setFE(0);
}

