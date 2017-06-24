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
    bool esHoja(NodoAVL *);
private:
    NodoAVL *raiz;
    int contador;
    int altura;
    void equilibrar(NodoAVL *, int, bool);
    void rsd(NodoAVL *);
    void rsi(NodoAVL *);
    void rdd(NodoAVL *);
    void rdi(NodoAVL *);
};

#endif /* ARBOLAVL_H */
