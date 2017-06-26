/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoRN.h
 * Author: fabio
 *
 * Created on June 25, 2017, 2:15 PM
 */

#ifndef NODORN_H
#define NODORN_H

class NodoRN {
public:
    NodoRN(int);
    ~NodoRN();
    int dato;
    bool color; // 0 = Rojo, 1 = Negro
    NodoRN *izquierdo, *derecho, *padre;
private:

};

#endif /* NODORN_H */

