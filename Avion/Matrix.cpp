//
//  Matrix.cpp
//  Avion
//
//  Created by Erick de Jesus Hernandez Cerecedo on 11/2/19.
//  Copyright © 2019 Erick de Jesus Hernandez Cerecedo. All rights reserved.
//

#include "Matrix.hpp"

Matrix::Matrix()
{
    rows = 4;
    columns = 4;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matriz[i][j] = (i==j)?1:0;
        }
    }
}

Matrix::Matrix(float _matriz[4][4], int _rows, int _columns)
{
    printf("Objeto matriz creado \n");
    
    rows = _rows;
    columns = _columns;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matriz[i][j] = _matriz[i][j];
        }
    }
}

Matrix::~Matrix()
{
    
}

int Matrix::getRows()
{
    return rows;
}

int Matrix::getColumns()
{
    return columns;
}

float Matrix::getValue(int _x, int _y)
{
    return matriz[_x][_y];
}

void Matrix::setValue(int _x, int _y, float _value)
{
    matriz[_x][_y] = _value;
}

void Matrix::setMatrix(float _matriz[4][4], int _rows, int _columns)
{
    rows = _rows;
    columns = _columns;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matriz[i][j] = _matriz[i][j];
        }
    }
}

void Matrix::LoadIdentity()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matriz[i][j] = (i==j)?1:0;
        }
    }
}

void Matrix::Multiplicacion(Matrix _A, Matrix _B)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matriz[i][j] = 0;
        }
    }
    
    for (int x=0; x < _A.getRows(); x++) {
        for (int y=0; y < _B.getColumns(); y++) {
            for (int z=0; z < _A.getColumns(); z++) {
                
                matriz[x][y] += _A.getValue(x,z) * _B.getValue(z,y);
            
            }
        }
    }
}

void Matrix::toString()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%f  ", matriz[i][j]);
        }
        printf("\n");
    }
}
