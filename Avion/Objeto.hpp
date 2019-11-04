//
//  Objeto.hpp
//  Avion
//
//  Created by Erick de Jesus Hernandez Cerecedo on 11/2/19.
//  Copyright © 2019 Erick de Jesus Hernandez Cerecedo. All rights reserved.
//

#ifndef Objeto_hpp
#define Objeto_hpp

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Librerias
#include <stdio.h>
#include <iostream>

// Clases
#include "Systema.hpp"
#include "Matrix.hpp"

class Objeto{
private:
    Systema *system;
    float _nave[4][17];
    float nave[4][17] =
    {
        //x1   x2   x3   x4   x5    x6.1  x7.2  x8.3  x9.4  x10.1 x11.2 x12.3 x13.4 x14.1 x15.2 x16.3 X17
        {-50,  50,  50, -50,  0,   -50,   50,   50,  -50,   50,  -50,  -50,   50,   120, -120, -120,  120,},
        //y1   y2   y3   y4   y5
        { 50,  50, -50, -50,  0,    50,   50,  -50,  -50,   75,   75,  -50,  -50,   30,   30,   30,   30,},
        //z1   z2   z3   z4   z5
        { 20,  20,  20,  20,  120, -130, -130, -130, -130, -160, -160, -160, -160, -30,  -30,  -100, -100,},
        
        { 1,   1,   1,   1,   1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,},
    };

public:
    Objeto();
    Objeto(Systema*);
    virtual ~Objeto();
    void draw();

    //void Xmodelado();
};

#endif /* Objeto_hpp */
