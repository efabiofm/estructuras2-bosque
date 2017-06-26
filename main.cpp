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
#include "ArbolRN.h"
#include "ArbolB.h"

using namespace std;

/*
 * 
 */
void menuPrincipal();
void menuSecundario();
void menuAVL();
void menuRN();
void menuB();

ArbolAVL *avl = new ArbolAVL();
ArbolRN *rn = new ArbolRN();

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
            case 2:
                menuRN();
                break;
            case 3:
                menuB();
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
    cout << "2. Árbol Rojo-Negro" <<endl;
    cout << "3. Árbol B" << endl;
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
        menuSecundario();
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

void menuRN(){
    int accion, dato;
    bool continuar;
    while(continuar){
        menuSecundario();
        cin >> accion;
        switch(accion){
            case 0:
                continuar = false;
                break;
            case 1:
                cout << "Digite el valor del nuevo nodo: ";
                cin >> dato;
                rn->insertar(dato);
                break;
            case 2:
                rn->imprimir();
                break;
            default:
                cout << "ERROR: Opción inválida" <<endl;
        }
    }
}

void menuB(){
    int accion, dato, grado;
    bool continuar;
    cout << "Indique el grado minimo del arbol: " << endl;
    cout << "El grado minimo es la base de las funciones necesarias \n"
            "para deducir el orden y mitad de los nodos.\n "
            "Orden = 2*t-1 || t = 3 -> orden = 5" << endl;
    cin >> grado;
    ArbolB *b = new ArbolB(grado);
    while(continuar){
        cout << "0. Ir atrás" <<endl;
        cout << "1. Insertar" <<endl;
        cout << "2. Buscar elemento" << endl;
        cout << "3. Imprimir" <<endl;
        cout << "Seleccione una opción: ";
        cin >> accion;
        switch(accion){
            case 0:
                continuar = false;
                break;
            case 1:
                cout << "Digite el valor del nuevo nodo: ";
                cin >> dato;
                b->insert(dato);
                break;
            case 2:
                cout << "Digite el valor que desea buscar: ";
                cin >> dato;
                (b->search(dato) != NULL)? cout << "Está" << endl : cout << "No está" << endl;
                break;
            case 3:
                cout << "Impresión Transversal: " << endl;
                b->traverse();
                cout << "\n";
                break;
            default:
                cout << "ERROR: Opción inválida" <<endl;
        }
    }
}
