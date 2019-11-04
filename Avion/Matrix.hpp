//
//  Matrix.hpp
//  Avion
//
//  Created by Erick de Jesus Hernandez Cerecedo on 11/2/19.
//  Copyright © 2019 Erick de Jesus Hernandez Cerecedo. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

// Librerias
#include <stdio.h>
#include <iostream>

class Matrix{
public:
    Matrix();
    Matrix(float[4][4], int, int);
    virtual ~Matrix();
    
    int rows;
    int columns;
    float matriz[4][4];

    int getRows();
    int getColumns();
    float getValue(int, int);
    void setValue(int, int, float);
    void setMatrix(float[4][4], int, int);
    void LoadIdentity();
    
    void Multiplicacion(Matrix, Matrix);
    void toString();
};

#endif /* Matrix_hpp */
