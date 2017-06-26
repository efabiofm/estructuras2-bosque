/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoRN.cpp
 * Author: fabio
 * 
 * Created on June 25, 2017, 2:15 PM
 */

#include "NodoRN.h"
#include <iostream>

NodoRN::NodoRN(int pdato) {
    dato = pdato;
    izquierdo = derecho = padre = NULL;
}

NodoRN::~NodoRN() {
}

int NodoRN::getDato(){
    return dato;
}

bool NodoRN::getColor(){
    return color;
}

void NodoRN::setDato(int pdato){
    dato = pdato;
}

void NodoRN::setColor(bool pcolor){
    color = pcolor;
}

NodoRN * NodoRN::getIzquierdo(){
    return izquierdo;
}

NodoRN * NodoRN::getDerecho(){
    return derecho;
}

NodoRN * NodoRN::getPadre(){
    return padre;
}

void NodoRN::setIzquierdo(NodoRN *pizq){
    izquierdo = pizq;
}

void NodoRN::setDerecho(NodoRN *pder){
    derecho = pder;
}

void NodoRN::setPadre(NodoRN *ppadre){
    padre = ppadre;
}
