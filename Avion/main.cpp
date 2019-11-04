//
//  main.cpp
//  Avion
//
//  Created by Erick de Jesus Hernandez Cerecedo on 11/1/19.
//  Copyright © 2019 Erick de Jesus Hernandez Cerecedo. All rights reserved.
//

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Librerias
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

// Clases
#include "Systema.hpp"
#include "Objeto.hpp"
#include "Matrix.hpp"

Systema miSistema;
Objeto  miObjeto(&miSistema);

void drawAxis()
{
    //glShadeModel(GL_SMOOTH);
    //X axis in red
    glColor3ub(30, 136, 229); // X Green
    glBegin(GL_LINES);
    glVertex3f(-300.0,0.0,0.0);
    glVertex3f(300.0,0.0,0.0);
    glEnd();
    glRasterPos3f(320.0f,0.0f,0.0f);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');

    //Y axis in green
    glColor3ub(183, 28, 28); // Y Red
    glBegin(GL_LINES);
    glVertex3f(0.0,-300.0,0.0);
    glVertex3f(0.0,300.0,0.0);
    glEnd();
    glRasterPos3f(-9.0f,320.0f,-0.0f);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
    
    //Z axis in blue
    glColor3ub( 0, 77, 64 ); // Z Green
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,-300.0);
    glVertex3f(0.0,0.0,300.0);
    glEnd();
    glRasterPos3f(0.0f,0.0f,320.0f);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Z');
    
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    
    miSistema.push();
    
    printf("1.Escala 0.2 de Matriz \n");
    miSistema.escalar(0.2, 0.2, 0.2);
    miObjeto.draw();
    
    printf("2.Tralado Z = 100 de Matriz \n");
    miSistema.transladar(1, 1, 100);
    miObjeto.draw();
    
    printf("2.Rotacion Y Avance X = 100 \n");
    miSistema.rotarY(90);
    miObjeto.draw();
    
    miSistema.transladar(100, 1, 1);
    miObjeto.draw();
    
    //miSistema.escalar(2, 2, 2);
    //miObjeto.draw();
    
    miSistema.pop();
    
    glFlush();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-640, 640, -360, 360, -360, 360);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,1,1,0,0,0,0,1,0);
    glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Examen Parcial 2");
    init();
    glutDisplayFunc(display);
    //glutIdleFunc(display);
    glutMainLoop();
 
    return 0;
}

