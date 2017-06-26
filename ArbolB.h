/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolB.h
 * Author: rodrigo
 *
 * Created on June 25, 2017, 1:52 PM
 */

#ifndef ARBOLB_H
#define ARBOLB_H
#include "NodoB.h"

class ArbolB
{
    NodoB *root; // Puntero a la raiz
    int t;  // Grado minimo del arbol, luego será usado en la formula 2*t-1 para obtener el orden del arbol y otras cosas
public:
    // Constructor
    ArbolB(int _t);
 
    // Funcion para atravesar el arbol
    void traverse();
 
    // Funcion para buscar una clave en el arbol
    NodoB* search(int k);
    
    // Funcion que inserta
    void insert(int k);
};

#endif /* ARBOLB_H */

