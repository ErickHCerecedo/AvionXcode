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
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 17; j++) {
            _nave[i][j] = 0;
        }
    }
    
    for (int x=0; x < 4/*A.getRows()*/; x++) {
        for (int y=0; y < 17/*B.getColumns()*/; y++) {
            for (int z=0; z < 4/*A.getColumns()*/; z++) {
                //matriz[x][y] += _A.getValue(x,z) * _B.getValue(z,y);
                _nave[x][y] += system->A.getValue(x, z) * nave[z][y];
            }
        }
    }
    
    //printf("Primer Matriz ");
    for (int i=0; i<4; i++) {
        for (int j=0; j<17; j++) {
            printf("%.2f    ", _nave[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    //NAVE PICO
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(_nave[0][0],_nave[1][0],_nave[2][0]); //p1
    glVertex3d(_nave[0][1],_nave[1][1],_nave[2][1]); //p2
    glVertex3d(_nave[0][2],_nave[1][2],_nave[2][2]); //p3
    glVertex3d(_nave[0][3],_nave[1][3],_nave[2][3]); //p4
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(_nave[0][4],_nave[1][4],_nave[2][4]); //p5
    glVertex3d(_nave[0][0],_nave[1][0],_nave[2][0]); //p1
    glVertex3d(_nave[0][4],_nave[1][4],_nave[2][4]); //p5
    glVertex3d(_nave[0][1],_nave[1][1],_nave[2][1]); //p2
    glVertex3d(_nave[0][4],_nave[1][4],_nave[2][4]); //p5
    glVertex3d(_nave[0][2],_nave[1][2],_nave[2][2]); //p3
    glVertex3d(_nave[0][4],_nave[1][4],_nave[2][4]); //p5
    glVertex3d(_nave[0][3],_nave[1][3],_nave[2][3]); //p4
    glEnd();
    
    
    //Nave Cuerpo.
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(_nave[0][5],_nave[1][5],_nave[2][5]); //p6
    glVertex3d(_nave[0][6],_nave[1][6],_nave[2][6]); //p7
    glVertex3d(_nave[0][7],_nave[1][7],_nave[2][7]); //p8
    glVertex3d(_nave[0][8],_nave[1][8],_nave[2][8]); //p9
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(_nave[0][0],_nave[1][0],_nave[2][0]); //p1
    glVertex3d(_nave[0][5],_nave[1][5],_nave[2][5]); //p6
    
    glVertex3d(_nave[0][1],_nave[1][1],_nave[2][1]); //p2
    glVertex3d(_nave[0][6],_nave[1][6],_nave[2][6]); //p7
    
    glVertex3d(_nave[0][2],_nave[1][2],_nave[2][2]); //p3
    glVertex3d(_nave[0][7],_nave[1][7],_nave[2][7]); //p8
    
    glVertex3d(_nave[0][2],_nave[1][2],_nave[2][2]); //p3
    glVertex3d(_nave[0][7],_nave[1][7],_nave[2][7]); //p8
    
    glVertex3d(_nave[0][3],_nave[1][3],_nave[2][3]); //p4
    glVertex3d(_nave[0][8],_nave[1][8],_nave[2][8]); //p9
    glEnd();
    
    
    //Nave Propulsor
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(_nave[0][9],_nave[1][9],_nave[2][9]); //p10
    glVertex3d(_nave[0][10],_nave[1][10],_nave[2][10]); //p11
    glVertex3d(_nave[0][11],_nave[1][11],_nave[2][11]); //p12
    glVertex3d(_nave[0][12],_nave[1][12],_nave[2][12]); //p13
    glEnd();
    
    
    glBegin(GL_LINES);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(_nave[0][5],_nave[1][5],_nave[2][5]); //p6
    glVertex3d(_nave[0][10],_nave[1][10],_nave[2][10]); //p11
    
    glVertex3d(_nave[0][6],_nave[1][6],_nave[2][6]); //p7
    glVertex3d(_nave[0][9],_nave[1][9],_nave[2][9]); //p10
    
    glVertex3d(_nave[0][7],_nave[1][7],_nave[2][7]); //p8
    glVertex3d(_nave[0][12],_nave[1][12],_nave[2][12]); //p13
    
    glVertex3d(_nave[0][8],_nave[1][8],_nave[2][8]); //p9
    glVertex3d(_nave[0][11],_nave[1][11],_nave[2][11]); //p12
    glEnd();
    
    
    //Nave AlaS
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2, 0.658, 0.101);
    glVertex3d(_nave[0][13],_nave[1][13],_nave[2][13]); //p1
    glVertex3d(_nave[0][14],_nave[1][14],_nave[2][14]); //p2
    glVertex3d(_nave[0][15],_nave[1][15],_nave[2][15]); //p3
    glVertex3d(_nave[0][16],_nave[1][16],_nave[2][16]); //p4
    glEnd();
}
