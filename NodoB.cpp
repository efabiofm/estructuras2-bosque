/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NodoB.h"

NodoB::NodoB(int _t, bool _hoja) {
    
    // Copiamos el grado minimo y el estado de hoja
    t = _t;
    hoja = _hoja;
 
    // Reservamos memoria para el numero maximo de claves posibles
    // y punteros hijos
    keys = new int[2*t-1];
    C = new NodoB *[2*t];
 
    // Inicializar el numero de claves en 0
    n = 0;
}

void NodoB::traverse()
{
    // Hay n claves y n+1 hijos, atravesamos a travez de los n hijos
    // y el primer hijo de n
    int i;
    for (i = 0; i < n; i++) {
        // Si este nodo no es hoja, entonces antes de imprimir
        // atravesamos el subarbol hijo
        if (hoja == false) {
            C[i]->traverse();
        }
        cout << " " << keys[i];
    }
 
    // Imprimir el subarbol anclado al ultimo hijo
    if (hoja == false) {
        C[i]->traverse();
    }
}

NodoB *NodoB::search(int k)
{
    // Encontrar la primera clave mayor o igual a k
    int i = 0;
    while (i < n && k > keys[i])
        i++;
 
    // Si la clave encontrada es igual a k, se devuelve
    if (keys[i] == k)
        return this;

    // Si la clave no se encuentra y este nodo es hoja, devuelve null
    if (hoja == true)
        return NULL;

    // Vamos al hijo
    return C[i]->search(k); 
}

void NodoB::insertNonFull(int k)
{
    // Inicializamos el indice como el indice mas a la derecha
    int i = n-1;
 
    if (hoja == true)
    {
        // La siguiente iteracion hace dos cosas:
        // a) Encuentra la posicion a la nueva clave por insertar
        // b) Mueve todas las claves mayores un espacio adelante
        while (i >= 0 && keys[i] > k)
        {
            keys[i+1] = keys[i];
            i--;
        }
 
        // Insertamos la nueva clave en la posicion encontrada
        keys[i+1] = k;
        n = n+1;
    } else {
        // Encuentra el hijo que tendrá la nueva clave
        while (i >= 0 && keys[i] > k)
            i--;
 
        // Evalua si el hijo encontrado está lleno
        if (C[i+1]->n == 2*t-1)
        {
            // Si está lleno, lo divide
            splitChild(i+1, C[i+1]);
            
            // Despues de dividir, la clave del medio C[i] se promueve
            // y C[i] se parte en dos. Aqui evaluamos cual de las dos nuevas
            // ramas contendrá la nueva clave
            if (keys[i+1] < k)
                i++;
        }
        C[i+1]->insertNonFull(k);
    }
}

void NodoB::splitChild(int i, NodoB *y)
{
    // Crear un nuevo nodo que contendrá (t-1) claves
    // de y
    NodoB *z = new NodoB(y->t, y->hoja);
    z->n = t - 1;
 
    // Copiamos las ultimas (t-1) claves de y a z
    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];
 
    // Si el nodo no es hoja, significa que tiene hijos, entonces 
    // copiamos los ultimos hijos de y a z
    if (y->hoja == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }
 
    // Se reduce el numero de claves en y
    y->n = t - 1;
 
    // Ya que este nodo va a tener un nuevo hijo,
    // creamos el espacio para el nuevo hijo
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];
 
    // Anclamos el nuevo hijo a este nodo
    C[i+1] = z;
 
    // Una clave de y se moverá a este nodo. Aqui se busca
    // la ubicacion para la nueva llave y se mueven todas las superiores
    // un espacio a la derecha o hacia adelante.
    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];
 
    // Copiamos la llame media de y a este nodo
    keys[i] = y->keys[t-1];
 
    // Incrementamos el numero de claves en el nodo
    n = n + 1;
}