/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolRN.h
 * Author: fabio
 *
 * Created on June 25, 2017, 2:19 PM
 */

#ifndef ARBOLRN_H
#define ARBOLRN_H

#include "NodoRN.h"

class ArbolRN {
public:
    ArbolRN();
    ~ArbolRN();
    void insertar(int);
    NodoRN* insertarRecursivo(NodoRN *, NodoRN *);
    void rotarIzquierda(NodoRN *, NodoRN *);
    void rotarDerecha(NodoRN *, NodoRN *);
    void equilibrar(NodoRN *, NodoRN *);
    void imprimir();
    int getAltura(NodoRN *);
    enum {ROJO, NEGRO};
private:
    NodoRN * raiz;
    void imprimirRecursivo(NodoRN *, int, int);
    int getEspacios(int, int);
};

#endif /* ARBOLRN_H */

