//
//  Systema.hpp
//  Avion
//
//  Created by Erick de Jesus Hernandez Cerecedo on 11/2/19.
//  Copyright © 2019 Erick de Jesus Hernandez Cerecedo. All rights reserved.
//

#ifndef Systema_hpp
#define Systema_hpp

#include <stdio.h>

class Systema{
private:
    float Msistema[4][4];
    float Mrotacion;
    float Mtraslacion;
    float Mescala;
    int pila;
public:
    Systema();
    ~Systema();
    void push();
    void pop();
};

#endif /* Systema_hpp */
