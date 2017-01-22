#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
/*#include<GL/gl.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#include <GL/glut.h>*/
#include <sstream>
using namespace std;

float ang_fan=0.0; //for fan movement
float distance_cloud=0.0;

void drawText(const char *text,int length, int x, int y, void* font ){
    glMatrixMode(GL_PROJECTION);
    double *matrix  = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0;i<length; i++){
        glutBitmapCharacter(font, (int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}

string ToString(int n)
{
    string S;                               /// string which will contain the result.
    stringstream convert;   /// stringstream used for the conversion.
    convert << n;                 /// Add the value of Number to the characters in the stream.

    S = convert.str();          /// Set Result to the content of the stream.
    cout << S << endl;
    return S;
}

void drawScene1(){
    GLfloat high_shininess[] = { 10.0 };  //does not vary that much
    GLfloat ball_Light_1[] = { 0.0,-1.0, 2.0, 0.5 };
    GLfloat ball_Light_2[] = { 0.0,-1.0, 2.0, 0.5 };
    GLfloat torus_Light_1[] = { 0.0,5.0, 5.0, 3.0 }; //first 3 parameters are x,y,z and 4th one is for spread,more the value less the spread
    GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };  //donot the the work
    GLfloat mat_diffusion_blue[] = { 0.0, 0.0, 5.0, 0.0 }; //used for color and its intensity
    GLfloat mat_diffusion_red[] = { 128.0, 0.0, 0.0, 0.0 };
    GLfloat mat_diffusion_white[] = { 1.0, 1.0, 1.0, 100.0 };
    GLfloat object_Light_pos[] = { 0.0,0.0, 2.0, 0.0 };

 //background variables start
    GLfloat mat_diffusion_blue_back[] = { 1.2, 2.0, 2.5, 0.1 }; //used for color and its intensity
    GLfloat light_pos_blue_back[] = { 0.0,0.0, 15.0, 0.5 };    //first 3 parameters are x,y,z and 4th one is for spread,more the value less the spread


    GLfloat mat_diffusion_white_back_cloud[] = { 240.0, 240.0, 240.0, 1.0 }; // use for cloud
    GLfloat light_pos_white_back_cloud[] = { 0.0,0.0,2.0, 0.0 };             //use for cloud
    GLfloat mat_diffusion_brown_back_road[] = { 20.0, 10.0, 8.0, 1.0 }; // use for road
    GLfloat light_pos_brown_back_road[] = { 0.0,0.0,22.0, 10.0 };   //use for road
    GLfloat mat_diffusion_yellow_back_sun[] = { 20.0, 20.0, 1.0, 1.0 }; // use for sun
    GLfloat light_pos_yellow_back_sun[] = { 0.0,0.0,50.0, 10.0 };   //use for sun
    GLfloat mat_diffusion_green_back_bush_2[] = { 0.5, 2.0, 0.0, 1.0 }; // use for bush 2
    GLfloat light_pos_green_back_bush_2[] = { -10.0,0.0,10.0, 10.0 };   //use for bush 2
    GLfloat mat_diffusion_green_back_bush_1[] = { 0.0, 40.0, 0.0, 10.0 }; // use for bush 2
    GLfloat light_pos_green_back_bush_1[] = { -10.0,0.0,100.0, 10.0 };   //use for bush 2

    GLUquadricObj *quad;
    quad =gluNewQuadric();
    //background variable ends
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor (1.0, 1.0, 1.0, 1.0);

	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0);

    //total background starts

    glPushMatrix();
        glTranslatef(0.0, 0.0, -7.0);
        glPushMatrix(); //start sky blue
            glTranslatef(0.0, 0.0, -10.0);
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_blue_back);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_blue_back);
            glScalef(2.0,1.0,1.0);
            glutSolidCube(20.0);
        glPopMatrix(); //end sky*/
        glPushMatrix(); //start road
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_brown_back_road);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_brown_back_road);
            glTranslatef(0.0,-8,-3.0);
            glScalef(4.0,0.8,1.0);
            glutSolidCube(10.0);
        glPopMatrix(); //end road
        glPushMatrix(); //start sun
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_yellow_back_sun);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_yellow_back_sun);
            glTranslatef(-14.0,6.5,1.0);
            // glScalef(4.0,0.7,1.0);
            glutSolidSphere(0.8,20,20);
        glPopMatrix(); //end sun
        glPushMatrix(); //start bush
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_green_back_bush_1);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_green_back_bush_1);
            glTranslatef(-16,-3.0,-2.5);
            glScalef(0.8,0.8,1.0);
            glutSolidSphere(3.0,20,20);
        glPopMatrix(); //end bush
        glPushMatrix(); //start bush2
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_green_back_bush_2);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_green_back_bush_2);
            glTranslatef(-13.5,-3.0,-2.0);
            glScalef(1.50,1.0,1.0);
            glutSolidSphere(2.5,20,20);
            glPopMatrix(); //end bush2
        glPushMatrix(); //start bush3
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_green_back_bush_2);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_green_back_bush_2);
            glTranslatef(13.5,-3.0,-2.0);
            glScalef(0.9,3.0,1.0);
            glutSolidSphere(2.1,20,20);
        glPopMatrix(); //end bush3
        glPushMatrix(); //start bush4
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_green_back_bush_2);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_green_back_bush_2);
            glTranslatef(15.5,-3.0,-2.0);
            glScalef(1.2,3.0,1.0);
            glutSolidSphere(2.1,20,20);
        glPopMatrix(); //end bush4
    glPushMatrix(); //start of many cloud
        glPushMatrix(); //start of first cloud
            glTranslatef(-9.0, 5.0, 0.0);
            glScalef(1.0,1.0,1.0);
            glTranslatef(distance_cloud, 0.0, 0.0);
       glPushMatrix();
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
            glTranslatef(0.5, 0.20, 0.0);
            glutSolidSphere(0.4,20,20);
        glPopMatrix();
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
            glutSolidSphere(0.2,20,20);
        glPopMatrix();
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
            glTranslatef(1.0, 0.0, 0.0);
            glutSolidSphere(0.2,20,20);
        glPopMatrix();
        glPushMatrix();

            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
            glRotatef(90, 0.0, 1.0, 0.0);
            gluCylinder(quad,0.2,0.2,1.0,40,40);
        glPopMatrix();
    glPopMatrix(); //end first cloud
        glPushMatrix(); //start of 2nd cloud
            glTranslatef(-7.0, 5.0, 1.0);
            glTranslatef(distance_cloud, 0.0, 1.0);
            glScalef(1.2,1.3,1.0);
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
            glTranslatef(0.5, 0.20, 0.0);
glutSolidSphere(0.4,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glTranslatef(1.0, 0.0, 0.0);

glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();

 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glRotatef(90, 0.0, 1.0, 0.0);
gluCylinder(quad,0.2,0.2,1.0,40,40);
    glPopMatrix();
    glPopMatrix(); //end 2nd cloud

    glPushMatrix(); //start of 3rd cloud
     glTranslatef(6.5, 5.0, 3.0);
       glTranslatef(distance_cloud, 0.0, 0.0);
     glScalef(1.5,1.3,1.0);

       glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glTranslatef(0.5, 0.20, 0.0);
glutSolidSphere(0.4,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glTranslatef(1.0, 0.0, 0.0);

glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();

 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glRotatef(90, 0.0, 1.0, 0.0);
gluCylinder(quad,0.2,0.2,1.0,40,40);
    glPopMatrix();
    glPopMatrix(); //end 3rd cloud

    glPushMatrix(); //start of 4th cloud
     glTranslatef(8.5, 6.0, 1.0);
      glTranslatef(distance_cloud, 0.0, 0.0);
     glScalef(1.5,1.3,1.0);

       glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glTranslatef(0.5, 0.20, 0.0);
glutSolidSphere(0.4,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glTranslatef(1.0, 0.0, 0.0);

glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();

 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glRotatef(90, 0.0, 1.0, 0.0);
gluCylinder(quad,0.2,0.2,1.0,40,40);
    glPopMatrix();
    glPopMatrix(); //end 4th cloud
    glPushMatrix(); //start of 5th cloud
     glTranslatef(-24.0, 4.5, 1.0);
      glTranslatef(distance_cloud, 0.0, 0.0);
     glScalef(1.2,1.5,1.0);

       glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glTranslatef(0.5, 0.20, 0.0);
glutSolidSphere(0.4,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glTranslatef(1.0, 0.0, 0.0);

glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();

 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glRotatef(90, 0.0, 1.0, 0.0);
gluCylinder(quad,0.2,0.2,1.0,40,40);
    glPopMatrix();
    glPopMatrix(); //end 5th cloud

     glPushMatrix(); //start of 6th cloud
     glTranslatef(-26.0, 5.0, 2.0);
      glTranslatef(distance_cloud, 0.0, 0.0);
     glScalef(1.2,0.8,1.0);

       glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glTranslatef(0.5, 0.20, 0.0);
glutSolidSphere(0.4,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glTranslatef(1.0, 0.0, 0.0);

glutSolidSphere(0.2,20,20);
    glPopMatrix();

     glPushMatrix();

 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_pos_white_back_cloud);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white_back_cloud);
   glRotatef(90, 0.0, 1.0, 0.0);
gluCylinder(quad,0.2,0.2,1.0,40,40);
    glPopMatrix();
    glPopMatrix(); //end 6th cloud


 glPopMatrix(); //end many  cloud
    glPopMatrix();
}
void drawScene2() {

    GLfloat high_shininess[] = { 10.0 };  //does not vary that much
    GLfloat ball_Light_1[] = { 0.0,-1.0, 2.0, 0.5 };
    GLfloat ball_Light_2[] = { 0.0,-1.0, 2.0, 0.5 };
    GLfloat torus_Light_1[] = { 0.0,5.0, 5.0, 3.0 }; //first 3 parameters are x,y,z and 4th one is for spread,more the value less the spread
    GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };  //donot the the work
    GLfloat mat_diffusion_blue[] = { 0.0, 0.0, 5.0, 0.0 }; //used for color and its intensity
    GLfloat mat_diffusion_red[] = { 128.0, 0.0, 0.0, 0.0 };
    GLfloat mat_diffusion_white[] = { 1.0, 1.0, 1.0, 100.0 };
    GLfloat object_Light_pos[] = { 0.0,0.0, 2.0, 0.0 };

   //background 2 variables start
   GLfloat mat_diffusion_yellow_back2[] = { 10.0, 2.0, 0.5, 1.0 }; //used for desert soil
    GLfloat light_pos_yellow_back2[] = { 0.0,0.0, 20.0, 0.3 };    //used for desert soil
  GLfloat mat_diffusion_blue_back2[] = { 0.0, 5.0, 200.0 ,1.0 }; //used for desert sky
    GLfloat light_pos_blue_back2[] = { 0.0,0.0, 20.0, 0.0};     //used for desert sky
     GLfloat mat_diffusion_green_back2_bush[] = { 0.0, 20.0, 0.0, 1.0 }; // use for bush_background2
     GLfloat light_pos_green_back2_bush[] = { 0.0,0.0,2.0, 0.0 };   //use for bush_background2
//background  2 variable ends


GLfloat mat_diffusion_yellow_back_sun[] = { 20.0, 20.0, 1.0, 1.0 }; // use for sun
     GLfloat light_pos_yellow_back_sun[] = { 0.0,0.0,20.0, 0.0 };   //use for sun



    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // glClearColor (0.5, 0.5, 0.5, 1.0);

	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0);

//total background starts

     glPushMatrix(); //total background starts
     glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();  //bottom soil starts

     glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   // COLOR CHANGE
                glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
                glLightfv(GL_LIGHT0, GL_POSITION, light_pos_yellow_back2);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_yellow_back2);

                glTranslatef(0.0,-8.5,0.0);
                glScalef(7.0,1.5,0.0);
    glutSolidSphere(3,40,40);

glPopMatrix(); //bottom soil ends
 glPushMatrix();  //sky starts

             glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
                glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
                glLightfv(GL_LIGHT0, GL_POSITION, light_pos_blue_back2);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_blue_back2);

                glTranslatef(0.0,-2.5,-10.0);
                glScalef(9.0,7.5,1.0);

                glutSolidCube(6);

glPopMatrix();   //sky ends
glPushMatrix(); //start sun

 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos_yellow_back_sun);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_yellow_back_sun);


glTranslatef(-14.0,6.5,1.0);

      // glScalef(4.0,0.7,1.0);
      glutSolidSphere(0.8,20,20);

    glPopMatrix(); //end sun


    glPushMatrix(); //start windmill_right

ang_fan += 2.0f;
	          if (ang_fan > 360) {
              ang_fan -= 360;
	}
	glTranslatef(11.0,0.0,-3.0);
	glRotatef( ang_fan,0.0,0.0,1.0);

  glPushMatrix();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)

	{

		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
glPopMatrix();
   glPushMatrix(); //Save the current state of transformations


	glBegin(GL_POLYGON);
	glVertex3f(-1.5, -0.25, 0.0);
	glVertex3f(0, -0.25, 0.0);
	glVertex3f(0, 0.25, 0.0);
	glVertex3f(-1.5, 0.25, 0.0);
glEnd();
glPopMatrix();

    glPushMatrix(); //Save the current state of transformations

	glTranslatef(1.5, 0.0, 0.0);
	glBegin(GL_POLYGON);

	glVertex3f(-1.5, -0.25, 0.0);
	glVertex3f(0, -0.25, 0.0);
	glVertex3f(0, 0.25, 0.0);
	glVertex3f(-1.5, 0.25, 0.0);
glEnd();
   glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
glBegin(GL_POLYGON);
	glVertex3f(-0.25, -1.5, 0.0);
	glVertex3f(0.25, -1.5, 0.0);
	glVertex3f(0.25, 0, 0.0);
	glVertex3f(-0.25, 0, 0.0);
glEnd();
glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, 1.5, 0.0);
glBegin(GL_POLYGON);
	glVertex3f(-0.25, -1.5, 0.0);
	glVertex3f(0.25, -1.5, 0.0);
	glVertex3f(0.25, 0, 0.0);
	glVertex3f(-0.25, 0, 0.0);
    glEnd();

   glPopMatrix();
  glPopMatrix(); //end windmill_rights

   glPushMatrix(); //windmill stick1_right_start
    glTranslatef(12.6,-2.7,-8.0);
    glScalef(0.4,3.2,1.0);
	glutSolidCube(2.0);
	glPopMatrix();    //windmill stick1_right_end


	 glPushMatrix(); //start windmill_left

ang_fan += 2.0f;
	          if (ang_fan > 360) {
              ang_fan -= 360;
	}
	glTranslatef(-11.0,0.0,-3.0);
	glRotatef( ang_fan,0.0,0.0,1.0);

  glPushMatrix();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)

	{

		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
glPopMatrix();
   glPushMatrix(); //Save the current state of transformations


	glBegin(GL_POLYGON);
	glVertex3f(-1.5, -0.25, 0.0);
	glVertex3f(0, -0.25, 0.0);
	glVertex3f(0, 0.25, 0.0);
	glVertex3f(-1.5, 0.25, 0.0);
glEnd();
glPopMatrix();

    glPushMatrix(); //Save the current state of transformations

	glTranslatef(1.5, 0.0, 0.0);
	glBegin(GL_POLYGON);

	glVertex3f(-1.5, -0.25, 0.0);
	glVertex3f(0, -0.25, 0.0);
	glVertex3f(0, 0.25, 0.0);
	glVertex3f(-1.5, 0.25, 0.0);
glEnd();
   glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
glBegin(GL_POLYGON);
	glVertex3f(-0.25, -1.5, 0.0);
	glVertex3f(0.25, -1.5, 0.0);
	glVertex3f(0.25, 0, 0.0);
	glVertex3f(-0.25, 0, 0.0);
glEnd();
glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, 1.5, 0.0);
glBegin(GL_POLYGON);
	glVertex3f(-0.25, -1.5, 0.0);
	glVertex3f(0.25, -1.5, 0.0);
	glVertex3f(0.25, 0, 0.0);
	glVertex3f(-0.25, 0, 0.0);
    glEnd();

   glPopMatrix();
  glPopMatrix(); //end windmill_left

   glPushMatrix(); //windmill stick1_left_start
    glTranslatef(-12.6,-2.7,-8.0);
    glScalef(0.4,3.2,1.0);
	glutSolidCube(2.0);
	glPopMatrix();    //windmill stick1_right_end

	 glPushMatrix(); //start bush1_background_2

 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos_green_back2_bush);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_green_back2_bush);


glTranslatef(-15.5,-4.5,-6.0);

      glScalef(0.15,2.0,1.0);
      glutSolidSphere(1.5,20,20);

    glPopMatrix(); //start bush1_background_2

glPushMatrix(); //start bush2_background_2

 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos_green_back2_bush);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_green_back2_bush);


glTranslatef(20.5,-7.0,-6.0);

      glScalef(2.0,2.0,1.0);
      glutSolidSphere(1.5,20,20);

    glPopMatrix(); //start bush2_background_2
glPopMatrix();//end background
//glutSwapBuffers();
}

//drawScene3


#endif // BACKGROUND_H_INCLUDED
