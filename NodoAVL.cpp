/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoAVL.cpp
 * Author: fabio
 * 
 * Created on June 23, 2017, 11:02 PM
 */

#include "NodoAVL.h"
#include <iostream>

NodoAVL::NodoAVL(const int pdato, NodoAVL * ppadre, NodoAVL * pizquierdo, NodoAVL * pderecho) {
    dato = pdato;
    FE = 0;
    padre = ppadre;
    izquierdo = pizquierdo;
    derecho = pderecho;
}

NodoAVL::NodoAVL(const int pdato) {
    dato = pdato;
    FE = 0;
    padre = NULL;
    izquierdo = NULL;
    derecho = NULL;
}

NodoAVL::NodoAVL(const int pdato, NodoAVL * ppadre) {
    dato = pdato;
    FE = 0;
    padre = ppadre;
    izquierdo = NULL;
    derecho = NULL;
}

NodoAVL::~NodoAVL() {
}

int NodoAVL::getDato() {
    return dato;
}

int NodoAVL::getFE() {
    return FE;
}

void NodoAVL::setDato(int pdato) {
    dato = pdato;
}

void NodoAVL::setFE(int pFE) {
    FE = pFE;
}

NodoAVL * NodoAVL::getIzquierdo() {
    return izquierdo;
}

NodoAVL * NodoAVL::getDerecho() {
    return derecho;
}

NodoAVL * NodoAVL::getPadre() {
    return padre;
}

void NodoAVL::setIzquierdo(NodoAVL * pizquierdo) {
    izquierdo = pizquierdo;
}

void NodoAVL::setDerecho(NodoAVL * pderecho) {
    derecho = pderecho;
}

void NodoAVL::setPadre(NodoAVL * ppadre) {
    padre = ppadre;
}