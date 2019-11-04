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

class Objeto{
private:
    float Mobjeto[1][1];
    float _Mobjeto[1][1];
public:
    void draw();
    void Xmodelado();
};

#endif /* Objeto_hpp */
