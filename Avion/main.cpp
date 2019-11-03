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

#include <stdlib.h>

void drawAxis()
{
    //glShadeModel(GL_SMOOTH);
    //X axis in red
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex3f(-3.0,0.0,0.0);
    glVertex3f(3.0,0.0,0.0);
    glEnd();
    //Y axis in green
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0,-3.0,0.0);
    glVertex3f(0.0,3.0,0.0);
    glEnd();
    //Z axis in blue
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,-3.0);
    glVertex3f(0.0,0.0,3.0);
    glEnd();
}

void display()
{
    int p;
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glFlush();
    
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4, 4, -4, 4, -4, 4);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,1,1,0,0,0,0,1,0);
    glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangulo a color");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}

