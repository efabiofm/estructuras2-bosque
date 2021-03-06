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

using namespace std;

ArbolAVL::ArbolAVL() {
    raiz = NULL;
}

ArbolAVL::~ArbolAVL() {
}

void ArbolAVL::insertar(const int dato) {
    NodoAVL *padre = NULL;
    NodoAVL *aux = raiz;
    while (aux && dato != aux->getDato()) {
        padre = aux;
        if (dato > aux->getDato()) {
            aux = aux->getDerecho();
        } else if (dato < aux->getDato()) {
            aux = aux->getIzquierdo();
        }
    }
    if (aux) return;
    if (!padre) {
        raiz = new NodoAVL(dato);
    } else if (dato < padre->getDato()) {
        padre->setIzquierdo(new NodoAVL(dato, padre));
        equilibrar(padre, IZQUIERDO, true);
    } else if (dato > padre->getDato()) {
        padre->setDerecho(new NodoAVL(dato, padre));
        equilibrar(padre, DERECHO, true);
    }
}

void ArbolAVL::equilibrar(NodoAVL * nodo, int rama, bool nuevo) {
    bool salir = false;
    while (nodo && !salir) {
        if (nuevo) {
            if (rama == IZQUIERDO) {
                nodo->setFE(nodo->getFE() - 1);
            } else {
                nodo->setFE(nodo->getFE() + 1);
            }
        } else if (rama == IZQUIERDO) {
            nodo->setFE(nodo->getFE() + 1);
        } else {
            nodo->setFE(nodo->getFE() - 1);
        }
        if (nodo->getFE() == 0) {
            salir = true;
        } else if (nodo->getFE() == -2) {
            if (nodo->getIzquierdo()->getFE() == 1) {
                rdd(nodo);
            } else {
                rsd(nodo);
            }
            salir = true;
        } else if (nodo->getFE() == 2) {
            if (nodo->getDerecho()->getFE() == -1) {
                rdi(nodo);
            }
            else {
                rsi(nodo);
            }
            salir = true;
        }
        if (nodo->getPadre()) {
            if (nodo->getPadre()->getDerecho() == nodo) {
                rama = DERECHO;
            } else {
                rama = IZQUIERDO;
            }
        }
        nodo = nodo->getPadre();
    }
}

void ArbolAVL::rsd(NodoAVL * nodo) {
    NodoAVL *Padre = nodo->getPadre();
    NodoAVL *P = nodo;
    NodoAVL *Q = P->getIzquierdo();
    NodoAVL *B = Q->getDerecho();

    if (Padre) {
        if (Padre->getDerecho() == P) {
            Padre->setDerecho(Q);
        }
        else {
            Padre->setIzquierdo(Q);
        }
    } else {
        raiz = Q;
    }

    P->setIzquierdo(B);
    Q->setDerecho(P);

    P->setPadre(Q);
    if (B) B->setPadre(P);
    Q->setPadre(Padre);

    P->setFE(0);
    Q->setFE(0);
}

void ArbolAVL::rsi(NodoAVL * nodo) {
    NodoAVL *Padre = nodo->getPadre();
    NodoAVL *P = nodo;
    NodoAVL *Q = P->getDerecho();
    NodoAVL *B = Q->getIzquierdo();

    if (Padre) {
        if (Padre->getDerecho() == P) {
            Padre->setDerecho(Q);
        }
        else {
            Padre->setIzquierdo(Q);
        }
    } else {
        raiz = Q;
    }

    P->setDerecho(B);
    Q->setIzquierdo(P);

    P->setPadre(Q);
    if (B) B->setPadre(P);
    Q->setPadre(Padre);

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

    if (Padre) {
        if (Padre->getDerecho() == nodo) {
            Padre->setDerecho(R);
        } else {
            Padre->setIzquierdo(R);
        }
    } else {
        raiz = R;
    }

    Q->setDerecho(B);
    P->setIzquierdo(C);
    R->setIzquierdo(Q);
    R->setDerecho(P);

    R->setPadre(Padre);
    Q->setPadre(R);
    P->setPadre(Q);
    if (B) B->setPadre(P);
    if (C) C->setPadre(Q);

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

    if (Padre) {
        if (Padre->getDerecho() == nodo) Padre->setDerecho(R);
        else Padre->setIzquierdo(R);
    } else {
        raiz = R;
    }

    P->setDerecho(B);
    Q->setIzquierdo(C);
    R->setIzquierdo(P);
    R->setDerecho(Q);

    R->setPadre(Padre);
    Q->setPadre(R);
    P->setPadre(Q);
    if (B) B->setPadre(P);
    if (C) C->setPadre(Q);

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

void ArbolAVL::imprimir() {
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
}

void ArbolAVL::imprimirRecursivo(NodoAVL* r, int nivel, int espacios) {
    if (nivel == 1) {
        r ? cout << r->getDato() : cout << " ";
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

int ArbolAVL::getAltura(NodoAVL *r) {
    if (!r) return 0;
    else {
        int izqAltura = getAltura(r->getIzquierdo());
        int derAltura = getAltura(r->getDerecho());
        return izqAltura > derAltura ? izqAltura + 1 : derAltura + 1;
    }
}

int ArbolAVL::getEspacios(int nivel, int altura) {
    int cant = 1;
    for (int i = nivel; i < altura; i++) {
        cant = 2 * cant + 1;
    }
    return cant;
}