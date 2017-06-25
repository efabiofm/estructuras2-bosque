/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolAVL.h
 * Author: fabio
 *
 * Created on June 23, 2017, 11:02 PM
 */

#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoAVL.h"

class ArbolAVL {
public:
    ArbolAVL();
    ~ArbolAVL();
    void insertar(const int);
    int getAltura(NodoAVL *);
    void imprimir();
private:
    NodoAVL *raiz;
    enum {IZQUIERDO, DERECHO};
    void equilibrar(NodoAVL *, int, bool);
    void rsd(NodoAVL *);
    void rsi(NodoAVL *);
    void rdd(NodoAVL *);
    void rdi(NodoAVL *);
    void imprimirRecursivo(NodoAVL *, int, int);
    int getEspacios(int, int);
};

#endif /* ARBOLAVL_H */

