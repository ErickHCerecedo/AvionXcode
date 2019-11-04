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

Objeto  miObjeto2(&miSistema);

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
    
    miSistema.push();
    drawAxis();
    
    printf("1.Escala 0.2 de Matriz \n");
    miSistema.escalar(0.2, 0.2, 0.2);
    miObjeto.draw();

    miSistema.pop();
    
    miSistema.push();
    drawAxis();
    printf("1.Escala 0.2 de Matriz \n");
    miSistema.escalar(0.2, 0.2, 0.2);
    miSistema.transladar(0, 0, 200);
    miSistema.rotarY(100);
    miObjeto2.draw();

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

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        // Rota XYZ
        case 'r':
        case 'R':
            printf("Rota todo \n");
            miSistema.rotarXYZ(1);
            break;
        // Rota y
        case 't':
        case 'T':
            printf("Adelante \n");
            miSistema.rotarY(1);
            break;
        // Rota -y
        case 'y':
        case 'Y':
            printf("Adelante \n");
            miSistema.rotarY(-1);
            break;
        // Rota X
        case 'g':
        case 'G':
            printf("Adelante \n");
            miSistema.rotarX(1);
            break;
        // Rota -X
        case 'h':
        case 'H':
            printf("Adelante \n");
            miSistema.rotarX(-1);
            break;
        // Rota Z
        case 'b':
        case 'B':
            printf("Adelante \n");
            miSistema.rotarZ(1);
            break;
            // Rota -Z
        case 'n':
        case 'N':
            printf("Adelante \n");
            miSistema.rotarZ(-1);
            break;
        // Adelante
        case 'w':
        case 'W':
            printf("Adelante \n");
            miSistema.transladar(6, 0, 0);
            break;
        // Atras
        case 's':
        case 'S':
            printf("Atras \n");
            miSistema.transladar(-6, 0, 0);
            break;
        // Izquierda
        case 'a':
        case 'A':
            printf("Izquierda \n");
            miSistema.transladar(0, 0, 6);
            break;
        // Derecha
        case 'd':
        case 'D':
            printf("Derecha \n");
            miSistema.transladar(0, 0, 6);
            break;
        // Arriba
        case 'z':
        case 'Z':
            printf("Arriba \n");
            miSistema.transladar(0, 6, 0);
            break;
        // Abajo
        case 'x':
        case 'X':
            printf("Abajo \n");
            miSistema.transladar(0, -6, 0);
            break;
        // Crece
        case 'o':
        case 'O':
            printf("Aumenta \n");
            miSistema.escalar(1.1, 1.1, 1.1);
            break;
        // Baja
        case 'p':
        case 'P':
            printf("Dismunuye \n");
            miSistema.escalar(0.9, 0.9, 0.9);
            break;
        case 27:   // escape
            exit(0);
            break;
            
    }
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
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

