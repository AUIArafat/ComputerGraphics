#ifndef MENU_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>
using namespace std;

int mouseX = 0, mouseY = 0;        /// Takes Mouse Coordinates

void mouse_motion(int x, int y)
{
    std::cerr << "\t mouse is at (" << x << ", " << y << ")" << std::endl;
    glutPostRedisplay();
}



void mouse(int button, int state, int x, int y)
{
    /// --------------------- Mouse Function For Start Display Screen -----------------------

    mouseX = x;
    mouseY = y;
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
            {

                    if(mouseX >=150 && mouseX <= 450)
                            if(mouseY >= 172 && mouseY <= 215)
                            {
                                cout<<"OK"<<endl;
//                                glutDisplayFunc(Background);
                            }
                    else if(mouseX >=325 && mouseX <= 980)
                            if(mouseY >= 320 && mouseY <= 400)
                            {
   //                             glutDisplayFunc(Background);
                            }
            }
                break;

            default:
            break;
    }

}


void DrawText(const char *text, int length, int x, int y, void* font)
{
    /// ------------------ Text Display Function, Font: Times Roman, Size: 24 --------------------

    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[100];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glPushMatrix();
     glClearColor(1.0,1.0,1.0,1.0);

        glLoadIdentity();
        glRasterPos2i(x, y);

        for(int i=0; i<length; i++)
            glutBitmapCharacter(font, (int)text[i]);

    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}



void Menu()
{

    glPushMatrix();
        glTranslatef(.8,.7,0);
        glScalef(.28,.28,.28);
//        Tree_L();
        glTranslatef(-.6,-.22,0);
//        Tree_R();
    glPopMatrix();

    glPushMatrix();

        glPushMatrix();
         glClearColor(1.0,1.0,1.0,1.0);

            glColor3f(0,1,0);
            glTranslatef(0,.3,0);
            glScalef(5,.2,1);
        glutSolidCube(.5);
        glPopMatrix();

        glColor3f(0,0,1);
        glPushMatrix();
            glTranslatef(0,-.3,0);
            glScalef(2,.4,1);
            glutSolidCube(.5);

        glPopMatrix();


        glPushMatrix();
            glColor3f(0,0,1);
            glTranslatef(0,-0.58,0);
            glScalef(2,.4,1);
            glutSolidCube(.5);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1,0,0);
            glTranslatef(0,-.86,0);
            glScalef(2,.4,1);
            glutSolidCube(.5);
        glPopMatrix();

    glPopMatrix();


    string text;
    glColor3f(1,1,1);
    text = "SWINGER";
    DrawText(text.data(), text.size(), 130, 350, GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(1,1,1);
    text = "MATCH";
    DrawText(text.data(), text.size(), 170, 330, GLUT_BITMAP_TIMES_ROMAN_24);

    text = "HIGH SCORE : ";
    DrawText(text.data(), text.size(), 270, 195, GLUT_BITMAP_TIMES_ROMAN_24);

    text = "Play";
    DrawText(text.data(), text.size(), 290, 135, GLUT_BITMAP_TIMES_ROMAN_24);

    text = "About";
    DrawText(text.data(), text.size(), 290, 85, GLUT_BITMAP_TIMES_ROMAN_24);

    text = "Exit";
    DrawText(text.data(), text.size(), 290, 25, GLUT_BITMAP_TIMES_ROMAN_24);
/*
    text = "Exit";
    DrawText(text.data(), text.size(), 290, 85);

*/
    glFlush();

}




#endif // MENU_H_INCLUDED
