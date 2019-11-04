//
//  Systema.cpp
//  Avion
//
//  Created by Erick de Jesus Hernandez Cerecedo on 11/2/19.
//  Copyright © 2019 Erick de Jesus Hernandez Cerecedo. All rights reserved.
//

#include "Systema.hpp"

Systema::Systema()
{
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            T.setValue(i, j, (i==j)?1:0);
            R.setValue(i, j, (i==j)?1:0);
            E.setValue(i, j, (i==j)?1:0);
            A.setValue(i, j, (i==j)?1:0);
        }
    }
}

Systema::~Systema()
{
    
}

void Systema::transladar(float _x, float _y, float _z)
{
    T.LoadIdentity();
    T.setValue(0, 3, _x);
    T.setValue(1, 3, _y);
    T.setValue(2, 3, _z);
    
    //A.setMatrix(_A, 4, 4);
    Matrix mAuxiliar = Matrix();
    // Mtrasladada tiene la multiplicacion de las matrices
    mAuxiliar.Multiplicacion(T, A);
    
    // Actualiza valor de _A matriz
    A.setMatrix(mAuxiliar);
    
    mAuxiliar.~Matrix();
}

void Systema::escalar(float _x, float _y, float _z)
{
    E.LoadIdentity();
    E.setValue(0, 0, _x);
    E.setValue(1, 1, _y);
    E.setValue(2, 2, _z);
    
    //A.setMatrix(_A, 4, 4);
    Matrix mAuxiliar = Matrix();
    // Mtrasladada tiene la multiplicacion de las matrices
    mAuxiliar.Multiplicacion(E, A);
    
    // Actualiza valor de matriz A
    A.setMatrix(mAuxiliar);
    
    mAuxiliar.~Matrix();
}

void Systema::rotarX(float deg)
{
    float angulo = deg * M_PI/180;
    float seno = sin(angulo);
    float cose = cos(angulo);
    
    R.LoadIdentity();
    R.setValue(1, 1, cose);
    R.setValue(1, 2, seno);
    R.setValue(2, 1, -seno);
    R.setValue(2, 2, cose);
    
    //A.setMatrix(_A, 4, 4);
    Matrix mAuxiliar = Matrix();
    // Mtrasladada tiene la multiplicacion de las matrices
    mAuxiliar.Multiplicacion(R, A);
    
    // Actualiza valor de _A matriz
    A.setMatrix(mAuxiliar);
    
    mAuxiliar.~Matrix();
    
}

void Systema::rotarY(float deg)
{
    float angulo = deg * M_PI/180;
    float seno = sin(angulo);
    float cose = cos(angulo);
    
    R.LoadIdentity();
    R.setValue(0, 0, cose);
    R.setValue(0, 2, -seno);
    R.setValue(2, 0, seno);
    R.setValue(2, 2, cose);
    
    //A.setMatrix(_A, 4, 4);
    Matrix mAuxiliar = Matrix();
    // Mtrasladada tiene la multiplicacion de las matrices
    mAuxiliar.Multiplicacion(R, A);
    
    // Actualiza valor de _A matriz
    A.setMatrix(mAuxiliar);
    
    mAuxiliar.~Matrix();
    
}

void Systema::rotarZ(float deg)
{
    float angulo = deg * M_PI/180;
    float seno = sin(angulo);
    float cose = cos(angulo);
    
    R.LoadIdentity();
    R.setValue(0, 0, cose);
    R.setValue(0, 1, seno);
    R.setValue(1, 0, -seno);
    R.setValue(1, 1, cose);
    
    //A.setMatrix(_A, 4, 4);
    Matrix mAuxiliar = Matrix();
    // Mtrasladada tiene la multiplicacion de las matrices
    mAuxiliar.Multiplicacion(R, A);
    
    // Actualiza valor de _A matriz
    A.setMatrix(mAuxiliar);
    
    mAuxiliar.~Matrix();
    
}

void Systema::rotarXYZ(float deg)
{
    rotarX(1);
    rotarY(1);
    rotarZ(1);
}

void Systema::push()
{
    Matrix *tmp;
    tmp = new Matrix();
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            tmp->matriz[i][j] = A.getValue(i, j);
        }
    }
    mystack.push(tmp);
    tmp = NULL;
}

void Systema::pop()
{
    Matrix *tmp;
    tmp = mystack.top();
    if (tmp) {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                A.setValue(i, j, tmp -> matriz[i][j]);
            }
        }
    }
    delete(tmp);
    mystack.pop();
}

void Systema::LoadIdentity(float M[4][4]){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            M[i][j] = (i==j)?1:0;
        }
    }
}

