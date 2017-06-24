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

#include <cstdlib>
#include "ArbolAVL.h"

using namespace std;

/*
 * 
 */
int main(void) {
    ArbolAVL *avl = new ArbolAVL();
    avl->insertar(7);
    avl->insertar(8);
    avl->insertar(9);
    avl->insertar(5);
    avl->insertar(6);
    avl->insertar(2);
    avl->insertar(14);
    avl->insertar(16);
    avl->insertar(13);
    return 0;
}

