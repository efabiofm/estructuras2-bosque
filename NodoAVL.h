/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoAVL.h
 * Author: fabio
 *
 * Created on June 23, 2017, 11:02 PM
 */

#ifndef NODOAVL_H
#define NODOAVL_H

class NodoAVL {
public:
    NodoAVL(const int, NodoAVL*, NodoAVL*, NodoAVL*);
    NodoAVL(const int);
    NodoAVL(const int, NodoAVL*);
    virtual ~NodoAVL();
    int getDato();
    int getFE();
    void setDato(int);
    void setFE(int);
    NodoAVL *getIzquierdo();
    NodoAVL *getDerecho();
    NodoAVL *getPadre();
    void setIzquierdo(NodoAVL *);
    void setDerecho(NodoAVL *);
    void setPadre(NodoAVL *);
private:
    int dato;
    int FE;
    NodoAVL *izquierdo;
    NodoAVL *derecho;
    NodoAVL *padre;
};

#endif /* NODOAVL_H */

