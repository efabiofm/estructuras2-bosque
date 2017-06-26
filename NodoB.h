/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoB.h
 * Author: rodrigo
 *
 * Created on June 25, 2017, 1:35 PM
 */

#ifndef NODOB_H
#define NODOB_H
#include<iostream>
using namespace std;
 
class NodoB
{
    int *keys;  // Arreglo de claves
    int t;      // Grado minimo del nodo, luego se usará en la formula 2*t-1 para saber el orden del arbol
    NodoB **C; // Arreglo de hijos
    int n;     // Cantidad actual de claves
    bool hoja; // Si el nodo es hoja o no
public:
    NodoB(int _t, bool _hoja);   // Constructor
    
    // Function para insertar una nueva clave en el subarbol anclado a este nodo.
    // Se asume que este nodo no está lleno cuando esta funcion se llama.
    void insertNonFull(int k);
 
    // Funcion para partir y, que es el hijo de este nodo. i es el indice de y
    // en el arreglo C. El hijo y tiene que estar lleno para que esta funcion se llame
    void splitChild(int i, NodoB *y);
 
    // Una funcion para pasar por todos los hijos de este nodo
    void traverse();
 
    // Funcion para buscar una clave hija de este nodo   
    NodoB *search(int k);   // devuelve NULL si no encuentra la clave.
    
friend class ArbolB;
};

#endif /* NODOB_H */

