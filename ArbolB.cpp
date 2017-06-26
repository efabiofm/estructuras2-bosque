/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ArbolB.h"
#include "NodoB.h"


ArbolB::ArbolB(int _t){
    root = NULL;  
    t = _t;
}

NodoB* ArbolB::search(int k) {
    return (root == NULL)? NULL : root->search(k);
}

void ArbolB::traverse() {
    if (root != NULL) {
        root->traverse();
    }
}

void ArbolB::insert(int k)
{
    if (root == NULL)
    {
        root = new NodoB(t, true); // Se hace el primer nodo (la raiz) 
        root->keys[0] = k;  // Insertamos la clave
        root->n = 1;  // Actualizamos la cantidad de claves
    }
    else
    {
        // Si el árbol está lleno, entonces este crece en profundidad
        if (root->n == 2*t-1)
        {
            // Hacemos el nuevo nodo
            NodoB *s = new NodoB(t, false);
 
            // Hacemos la raiz vieja el primer hijo del nuevo nodo
            s->C[0] = root;
 
            // Partimos la raiz y movemos una clave a la nueva raiz
            s->splitChild(0, root);
 
            // La nueva raiz ahora tiene dos hijos. Ahora decidimos
            // cual de la dos tendrá la nueva clave
            int i = 0;
            if (s->keys[0] < k) {
                i++;
            }
            s->C[i]->insertNonFull(k);
 
            // Change root
            root = s;
        }
        else
        {
            // Si la raiz no está llena, se usa el algoritmo para insertar a un nodo no lleno
            root->insertNonFull(k);
        }
    }
}