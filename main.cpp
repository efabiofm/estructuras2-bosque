/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: fabio
 *
 * Created on June 23, 2017, 10:49 PM
 */

#include <iostream>
#include "ArbolAVL.h"

using namespace std;

/*
 * 
 */
void menuPrincipal();
void menuSecundario();
void menuAVL();

ArbolAVL *avl = new ArbolAVL();

int main(void) {
    int tipo;
    bool continuar = true;
    while(continuar){
        menuPrincipal();
        cin >> tipo;
        switch(tipo){
            case 0:
                continuar = false;
                break;
            case 1:
                menuAVL();
                break;
            default:
                cout << "ERROR: Opción inválida" <<endl;
        }
    }
    return 0;
}

void menuPrincipal(){
    cout << "ARBOLES DE BÚSQUEDA" <<endl;
    cout << "===================" <<endl;
    cout << "0. Salir" << endl;
    cout << "1. Árbol AVL" <<endl;
    cout << "Seleccione una opción: ";
}

void menuSecundario(){
    cout << "0. Ir atrás" <<endl;
    cout << "1. Insertar" <<endl;
    cout << "2. Imprimir" <<endl;
    cout << "Seleccione una opción: ";
}

void menuAVL(){
    int accion, dato;
    bool continuar;
    while(continuar){
        cout << "0. Ir atrás" <<endl;
        cout << "1. Insertar" <<endl;
        cout << "2. Imprimir" <<endl;
        cout << "Seleccione una opción: ";
        cin >> accion;
        switch(accion){
            case 0:
                continuar = false;
                break;
            case 1:
                cout << "Digite el valor del nuevo nodo: ";
                cin >> dato;
                avl->insertar(dato);
                break;
            case 2:
                avl->imprimir();
                break;
            default:
                cout << "ERROR: Opción inválida" <<endl;
        }
    }
}

