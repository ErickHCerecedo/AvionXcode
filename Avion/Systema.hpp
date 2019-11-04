//
//  Systema.hpp
//  Avion
//
//  Created by Erick de Jesus Hernandez Cerecedo on 11/2/19.
//  Copyright © 2019 Erick de Jesus Hernandez Cerecedo. All rights reserved.
//

#ifndef Systema_hpp
#define Systema_hpp

// Librerias
#include <stdio.h>
#include <iostream>
#include <stack>
#include <math.h>

// Clases
#include "Matrix.hpp"


class Systema{
public:
    Systema();
    ~Systema();
    
    void transladar(float, float, float);
    void escalar(float, float, float);
    void rotarX(float);
    void rotarY(float);
    void rotarZ(float);
    void rotarXYZ(float);
    
    void clonarA();
    
    float _T[4][4], _R[4][4], _E[4][4], _A[4][4];
    
    Matrix T = Matrix(_T,4,4);
    Matrix R = Matrix(_R,4,4);
    Matrix E = Matrix(_E,4,4);
    Matrix A = Matrix(_A,4,4);
    
    std::stack<Matrix *>mystack;
    
    void push();
    void pop();
    void LoadIdentity(float[][4]);
};

#endif /* Systema_hpp */
