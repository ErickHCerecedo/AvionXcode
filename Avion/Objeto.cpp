//
//  Objeto.cpp
//  Avion
//
//  Created by Erick de Jesus Hernandez Cerecedo on 11/2/19.
//  Copyright © 2019 Erick de Jesus Hernandez Cerecedo. All rights reserved.
//

#include "Objeto.hpp"

Objeto::Objeto()
{
    
}

Objeto::Objeto(Systema * _system)
{
    system = _system;
}

Objeto::~Objeto()
{
    system = NULL;
}

void Objeto::draw()
{
    //NAVE PICO
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(nave[0][0],nave[1][0],nave[2][0]); //p1
    glVertex3d(nave[0][1],nave[1][1],nave[2][1]); //p2
    glVertex3d(nave[0][2],nave[1][2],nave[2][2]); //p3
    glVertex3d(nave[0][3],nave[1][3],nave[2][3]); //p4
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(nave[0][4],nave[1][4],nave[2][4]); //p5
    glVertex3d(nave[0][0],nave[1][0],nave[2][0]); //p1
    glVertex3d(nave[0][4],nave[1][4],nave[2][4]); //p5
    glVertex3d(nave[0][1],nave[1][1],nave[2][1]); //p2
    glVertex3d(nave[0][4],nave[1][4],nave[2][4]); //p5
    glVertex3d(nave[0][2],nave[1][2],nave[2][2]); //p3
    glVertex3d(nave[0][4],nave[1][4],nave[2][4]); //p5
    glVertex3d(nave[0][3],nave[1][3],nave[2][3]); //p4
    glEnd();
    
    
    //Nave Cuerpo.
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(nave[0][5],nave[1][5],nave[2][5]); //p6
    glVertex3d(nave[0][6],nave[1][6],nave[2][6]); //p7
    glVertex3d(nave[0][7],nave[1][7],nave[2][7]); //p8
    glVertex3d(nave[0][8],nave[1][8],nave[2][8]); //p9
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(nave[0][0],nave[1][0],nave[2][0]); //p1
    glVertex3d(nave[0][5],nave[1][5],nave[2][5]); //p6
    
    glVertex3d(nave[0][1],nave[1][1],nave[2][1]); //p2
    glVertex3d(nave[0][6],nave[1][6],nave[2][6]); //p7
    
    glVertex3d(nave[0][2],nave[1][2],nave[2][2]); //p3
    glVertex3d(nave[0][7],nave[1][7],nave[2][7]); //p8
    
    glVertex3d(nave[0][2],nave[1][2],nave[2][2]); //p3
    glVertex3d(nave[0][7],nave[1][7],nave[2][7]); //p8
    
    glVertex3d(nave[0][3],nave[1][3],nave[2][3]); //p4
    glVertex3d(nave[0][8],nave[1][8],nave[2][8]); //p9
    glEnd();
    
    
    //nave Propulsor
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(nave[0][9],nave[1][9],nave[2][9]); //p10
    glVertex3d(nave[0][10],nave[1][10],nave[2][10]); //p11
    glVertex3d(nave[0][11],nave[1][11],nave[2][11]); //p12
    glVertex3d(nave[0][12],nave[1][12],nave[2][12]); //p13
    glEnd();
    
    
    glBegin(GL_LINES);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(nave[0][5],nave[1][5],nave[2][5]); //p6
    glVertex3d(nave[0][10],nave[1][10],nave[2][10]); //p11
    
    glVertex3d(nave[0][6],nave[1][6],nave[2][6]); //p7
    glVertex3d(nave[0][9],nave[1][9],nave[2][9]); //p10
    
    glVertex3d(nave[0][7],nave[1][7],nave[2][7]); //p8
    glVertex3d(nave[0][12],nave[1][12],nave[2][12]); //p13
    
    glVertex3d(nave[0][8],nave[1][8],nave[2][8]); //p9
    glVertex3d(nave[0][11],nave[1][11],nave[2][11]); //p12
    glEnd();
    
    
    //nave AlaS
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(nave[0][13],nave[1][13],nave[2][13]); //p1
    glVertex3d(nave[0][14],nave[1][14],nave[2][14]); //p2
    glVertex3d(nave[0][15],nave[1][15],nave[2][15]); //p3
    glVertex3d(nave[0][16],nave[1][16],nave[2][16]); //p4
    glEnd();
}
