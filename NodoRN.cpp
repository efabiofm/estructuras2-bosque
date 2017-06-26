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

