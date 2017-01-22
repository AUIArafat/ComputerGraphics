#include <bits/stdc++.h>
#include<GL/gl.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#include <GL/glut.h>
#include <sstream>
#include <windows.h>   // for PlaySound()
#include <Mmsystem.h>
#define READ() freopen("Input.txt", "r", stdin)
#define WRITE() freopen("Output.txt", "w", stdout)
#define SND_FILENAME 0x20000
#define SND_LOOP 8
#define SND_ASYNC 1
#include "FirstScene.h"
#include "background.h"
using namespace std;

//Initializes 3D rendering
char quote[6][80];
int numberOfQuotes = 0;
char title[] = "Full-Screen & Windowed Mode";
bool fullScreenMode = true;
void initRendering() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

}
GLfloat UpwardsScrollVelocity = -10.0;
float view = 10.0;
void timeTick(void)
{
	if (UpwardsScrollVelocity< -600)
		view -= 0.000011;
	if (view < 0) { view = 20; UpwardsScrollVelocity = -10.0; }
	//  exit(0);
	UpwardsScrollVelocity -= 0.1;
	glutPostRedisplay();

}

void RenderToDisplay()
{
	int l, lenghOfQuote, i;

	//glTranslatef(0.0, -100, UpwardsScrollVelocity);

glTranslatef(0.0,30.0,0.0);
	glRotatef(-20, 1.0, 0.0, 0.0);
	glScalef(0.05, 0.05, 0.1);



	for (l = 0; l<numberOfQuotes; l++)
	{
		lenghOfQuote = (int)strlen(quote[l]);
		glPushMatrix();
		glTranslatef(-(lenghOfQuote * 37), -(l * 200), 0.0);
		for (i = 0; i < lenghOfQuote; i++)
		{
		    glClearColor(0.0,0.5,1.0,1.0);
		    glColor3f(0.0,0.0,0.0);
			//glColor3f((UpwardsScrollVelocity / 10) + 300 + (l * 10), (UpwardsScrollVelocity / 10) + 300 + (l * 10), 0.0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, quote[l][i]);


		}
		glPopMatrix();
	}

}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 1.0, 3200);
	glMatrixMode(GL_MODELVIEW);
}

    float angle = 0.0;
    float _cameraAngle = 0.0;
    float _angle =0.0;
    float _ang_tri = 0.0;
    float up_l =0.0;   // left rotate variable
    float up_r =0.0;   //right rotate variable
    int pause_checker=0;
    void update_left(int value);  //the function used to rotate left
    void update_right(int value); //the function used to rotate right
    void update_obj1(int value);
    void update_obj2(int value);
    void update_obj3(int value);
    void update_obj4(int value);
    void update_obj5(int value);
    void update_obj6(int value);
    void update_cloud(int value);
    float X1 = .8,Y1 = -.4, X2 = 1.6, Y2 = -.4, X3 = 1.6, Y3 = .4, X4 = .8, Y4 = .4;   //for right (blue) sphere
    float Z1 =0, Z2=0,Z3=0,Z4=0; //for right (blue) sphere
    float E1 = -0.28,F1 = -0.31, E2 = 0.26, F2 = -0.31, E3 = 0.26, F3 = 0.31, E4 = -0.28, F4 = 0.31; //FOR OBJECT 1
    float G1 = -0.28,H1 = -0.31, G2 = 0.26, H2 = -0.31, G3 = 0.26, H3 = 0.34, G4 = -0.28, H4 = 0.34; //FOR OBJECT 2
    float I1 = -0.29,J1 = -0.32, I2 = 0.28, J2 = -0.32, I3 = 0.28, J3 = 0.32, I4 = -0.29, J4 = 0.32; //FOR OBJECT 4
    float A1 = -0.4,B1 = -0.4, A2 = 0.4, B2 = -0.4, A3 = 0.4, B3 = 0.4, A4 = -0.4, B4 = 0.4;  //FOR OBJECT 5
    float C1 = -0.4,D1 = -0.4, C2 = 0.4, D2 = -0.4, C3 = 0.4, D3 = 0.4, C4 = -0.4, D4 = 0.4;  //FOR OBJECT 3
    float O1 = -0.41,P1 = -0.43, O2 = 0.41, P2 = -0.43, O3 = 0.41, P3 = 0.43, O4 = -0.41, P4 = 0.43;  //FOR OBJECT 6
    float K1=-1.6,L1=-0.4,K2=-0.8,L2=-0.4,K3=-0.8,L3=0.4,K4=-1.6,L4=0.4; //for left(red) sphere
    float M1=0 ,M2 =0,M3=0,M4 =0;  //for left(red) sphere
    float cubeMatrixEF[100]; //for object 1
    float cubeMatrixGH[100]; //for object 2
    float bTorus[100]; //for object 3
    float cubeMatrixIJ[100]; //for object 4
    float aTorus[100];  //for object 5
    float cubeMatrixOP[100]; //for object 6
    int i = 0;
    double highScore;
    int cnt = 0;
    float Z11 =0, Z22=0,Z33=0,Z44=0;   //for right (blue) sphere
    float Y11 =0, Y22=0,Y33=0,Y44=0;   //for right (blue) sphere
    float X11 =0, X22=0,X33=0,X44=0;   //for right (blue) sphere
    bool flag = false;
    float M11 =0, M22=0,M33=0,M44=0;   //for left (red) sphere
    float L11 =0, L22=0,L33=0,L44=0;   //for left (red) sphere
    float K11 =0, K22=0,K33=0,K44=0;   //for left (red) sphere
    float start =0.0; //for object falling
    float distance1 =4.0;
    float distance2=10.0;
    float distance3=16.0;
    float distance4=22.0;
    float distance5=35.0;
    float distance6=44.0;
    int checkTouch = 0;
   //for cloud movement

    double Score = 0.0;
    double level = 1;
    int key = 0;
    double Time = 0.0;


    std::string playerName = "";

void drawText(const char *text,int length, int x, int y ){
    glMatrixMode(GL_PROJECTION);
    double *matrix  = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0;i<length; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}
//Draws the 3D scene
void drawScene() {
    GLfloat high_shininess[] = { 10.0 };  //does not vary that much
    GLfloat ball_Light_1[] = { 0.0,-1.0, 2.0, 0.5 };
    GLfloat ball_Light_2[] = { 0.0,-1.0, 2.0, 0.5 };
    GLfloat torus_Light_1[] = { 0.0,5.0, 5.0, 3.0 }; //first 3 parameters are x,y,z and 4th one is for spread,more the value less the spread
    GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };  //donot the the work
    GLfloat mat_diffusion_blue[] = { 0.0, 0.0, 5.0, 0.0 }; //used for color and its intensity
    GLfloat mat_diffusion_red[] = { 128.0, 0.0, 0.0, 0.0 };
    GLfloat mat_diffusion_white[] = { 1.0, 1.0, 1.0, 100.0 };
    GLfloat object_Light_pos[] = { 0.0,0.0, 2.0, 0.0 };
    GLfloat mat_diffusion_black[] = { 0.0, 0.0, 0.0, 100.0 };
    GLfloat object_Light_pos_black[] = { 0.0,0.0, 4.0, 0.0 };

    //PlaySound("C:\\Users\\Md.Arafatul\\Desktop\\Happy-electronic-music.mp3",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
    if(Time>=1000 && Time<2500){
        drawScene2();
        level = 2;
    }
    else if(Time<1000){
        level = 1;
        drawScene1();
        //firstScene();
    }

     else if( Time>=2500){
        level = 3;
        drawScene1();
        //firstScene();
    }

    //total background ends
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

    //*******************
    GLfloat modelView[16]; //for right sphere
    //GLfloat modelView2[16]; //for left sphere
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //*******************

    glPushMatrix();
         if(checkTouch==1){
            glScalef(.7, .7, 1);
         }
        if(checkTouch==2)
            glScalef(1.1, 1.1, 1);
        glTranslatef(0.0,-1.2,0.0);
        glRotatef(angle,0.0,0.0,1.0);
        glPushMatrix();
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
            glBegin(GL_POLYGON);
            glVertex3f(X1,Y1,Z1);
            glVertex3f(X2,Y2,Z2);
            glVertex3f(X3,Y3,Z3);
            glVertex3f(X4,Y4,Z4);
            glEnd();
            glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
            X11 = X1*modelView[0] + Y1*modelView[4] + Z1*modelView[8] + modelView[12];
            Y11 = X1*modelView[1] + Y1*modelView[5] + Z1*modelView[9] + modelView[13];
            Z11 = X1*modelView[2] + Y1*modelView[6] + Z1*modelView[10] + modelView[14];
            X22 = X2*modelView[0] + Y2*modelView[4] + Z2*modelView[8] + modelView[12];
            Y22 = X2*modelView[1] + Y2*modelView[5] + Z2*modelView[9] + modelView[13];
            Z22 = X2*modelView[2] + Y2*modelView[6] + Z2*modelView[10] + modelView[14];
            X33 = X3*modelView[0] + Y3*modelView[4] + Z3*modelView[8] + modelView[12];
            Y33 = X3*modelView[1] + Y3*modelView[5] + Z3*modelView[9] + modelView[13];
            Z33 = X3*modelView[2] + Y3*modelView[6] + Z3*modelView[10] + modelView[14];
            X44 = X4*modelView[0] + Y4*modelView[4] + Z4*modelView[8] + modelView[12];
            Y44 = X4*modelView[1] + Y4*modelView[5] + Z4*modelView[9] + modelView[13];
            Z44 = X4*modelView[2] + Y4*modelView[6] + Z4*modelView[10] + modelView[14];

            glBegin(GL_POLYGON);
            glVertex3f(K1,L1,M1);
            glVertex3f(K2,L2,M2);
            glVertex3f(K3,L3,M3);
            glVertex3f(K4,L4,M4);
            glEnd();
            //
            //glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
              // glGetFloatv(GL_MODELVIEW_MATRIX, modelView2);
            K11 = K1*modelView[0] + L1*modelView[4] + M1*modelView[8] + modelView[12];
            L11 = K1*modelView[1] + L1*modelView[5] + M1*modelView[9] + modelView[13];
            M11 = K1*modelView[2] + L1*modelView[6] + M1*modelView[10] + modelView[14];
            K22 = K2*modelView[0] + L2*modelView[4] + M2*modelView[8] + modelView[12];
            L22 = K2*modelView[1] + L2*modelView[5] + M2*modelView[9] + modelView[13];
            M22 = K2*modelView[2] + L2*modelView[6] + M2*modelView[10] + modelView[14];
            K33 = K3*modelView[0] + L3*modelView[4] + M3*modelView[8] + modelView[12];
            L33 = K3*modelView[1] + L3*modelView[5] + M3*modelView[9] + modelView[13];
            M33 = K3*modelView[2] + L3*modelView[6] + M3*modelView[10] + modelView[14];
            K44 = K4*modelView[0] + L4*modelView[4] + M4*modelView[8] + modelView[12];
            L44 = K4*modelView[1] + L4*modelView[5] + M4*modelView[9] + modelView[13];
            M44 = K4*modelView[2] + L4*modelView[6] + M4*modelView[10] + modelView[14];
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, torus_Light_1);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_white);
            glutSolidTorus(.1, 1.2, 35, 35);
        glPopMatrix(); //Undo the move to the center of the triangle
        glPushMatrix();

            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, ball_Light_1);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_blue);
            glTranslatef(1.2, 0.0, 0.0); //Move to the center of the triangle
             //Rotate about the the vector (1, 2, 3)
            glutSolidSphere(0.4,20,20);
        glPopMatrix();

        glPushMatrix();
        //Save the current state of transformations
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, ball_Light_1);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_red);
            glTranslatef(-1.2, 0.0, 0.0); //Move to the center of the triangle
             //Rotate about the the vector (1, 2, 3)
            glutSolidSphere(0.4,20,20);
        glPopMatrix();
    glPopMatrix();



    if (start=1){
        glPushMatrix();
        //object `1 // blue cube
            glPushMatrix();
                glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
                glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); // COLOR CHANGE
                glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
//                glLightfv(GL_LIGHT0, GL_POSITION, object_Light_1);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_blue);
                glScalef(3,1,1);
                glTranslatef(-.6,distance1,0.0);
                glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
                cubeMatrixEF[0] = E1*modelView[0] + F1*modelView[4] + modelView[12];
                cubeMatrixEF[1] = E1*modelView[1] + F1*modelView[5] + modelView[13];
                cubeMatrixEF[2] = E2*modelView[0] + F2*modelView[4] + modelView[12];
                cubeMatrixEF[3] = E2*modelView[1] + F2*modelView[5] + modelView[13];
                cubeMatrixEF[4] = E3*modelView[0] + F3*modelView[4] + modelView[12];
                cubeMatrixEF[5] = E3*modelView[1] + F3*modelView[5] + modelView[13];
                cubeMatrixEF[6] = E4*modelView[0] + F4*modelView[4] + modelView[12];
                cubeMatrixEF[7] = E4*modelView[1] + F4*modelView[5] + modelView[13];
                glBegin(GL_POLYGON);
                glVertex2f(E1,F1);
                glVertex2f(E2,F2);
                glVertex2f(E3,F3);
                glVertex2f(E4,F4);
                glEnd();
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
                glutSolidCube(0.5);
            glPopMatrix();



//object 2(blue) sphere// bonus
            glPushMatrix();
                glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
                glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   // COLOR CHANGE
                glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
                glLightfv(GL_LIGHT0, GL_POSITION, object_Light_pos);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_blue);
                glTranslatef(0.0,distance2,0.0);
                glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
                bTorus[0] = C1*modelView[0] + D1*modelView[4] + modelView[12];
                bTorus[1] = C1*modelView[1] + D1*modelView[5] + modelView[13];
                bTorus[2] = C2*modelView[0] + D2*modelView[4] + modelView[12];
                bTorus[3] = C2*modelView[1] + D2*modelView[5] + modelView[13];
                bTorus[4] = C3*modelView[0] + D3*modelView[4] + modelView[12];
                bTorus[5] = C3*modelView[1] + D3*modelView[5] + modelView[13];
                bTorus[6] = C4*modelView[0] + D4*modelView[4] + modelView[12];
                bTorus[7] = C4*modelView[1] + D4*modelView[5] + modelView[13];
                glBegin(GL_POLYGON);
                glVertex2f(C1,D1);
                glVertex2f(C2,D2);
                glVertex2f(C3,D3);
                glVertex2f(C4,D4);
                glEnd();
                glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
                glutSolidSphere(0.4,20,20);
            glPopMatrix();


            //object3 (red cube)
            glPushMatrix();
             glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

                glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   // COLOR CHANGE
                glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
//                glLightfv(GL_LIGHT0, GL_POSITION, object_Light_1);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_red);
                glTranslatef(1,distance3,0.0);
                glScalef(2.5,.8,1);
                glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
                cubeMatrixOP[0] = O1*modelView[0] + P1*modelView[4] + modelView[12];
                cubeMatrixOP[1] = O1*modelView[1] + P1*modelView[5] + modelView[13];
                cubeMatrixOP[2] = O2*modelView[0] + P2*modelView[4] + modelView[12];
                cubeMatrixOP[3] = O2*modelView[1] + P2*modelView[5] + modelView[13];
                cubeMatrixOP[4] = O3*modelView[0] + P3*modelView[4] + modelView[12];
                cubeMatrixOP[5] = O3*modelView[1] + P3*modelView[5] + modelView[13];
                cubeMatrixOP[6] = O4*modelView[0] + P4*modelView[4] + modelView[12];
                cubeMatrixOP[7] = O4*modelView[1] + P4*modelView[5] + modelView[13];
                glBegin(GL_POLYGON);
                glVertex2f(O1,P1);
                glVertex2f(O2,P2);
                glVertex2f(O3,P3);
                glVertex2f(O4,P4);
                glEnd();
                glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
                glutSolidCube(0.8);
            glPopMatrix();
        glPopMatrix();

        //object 4(red cube)
        glPushMatrix();
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
                glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   // COLOR CHANGE
                glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
//                glLightfv(GL_LIGHT0, GL_POSITION, object_Light_1);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_red);
                glTranslatef(0.0,distance4,0.0);
                glScalef(2,1,1);
                glGetFloatv(GL_MODELVIEW_MATRIX, modelView);

                cubeMatrixGH[0] = G1*modelView[0] + H1*modelView[4] + modelView[12];
                cubeMatrixGH[1] = G1*modelView[1] + H1*modelView[5] + modelView[13];
                cubeMatrixGH[2] = G2*modelView[0] + H2*modelView[4] + modelView[12];
                cubeMatrixGH[3] = G2*modelView[1] + H2*modelView[5] + modelView[13];
                cubeMatrixGH[4] = G3*modelView[0] + H3*modelView[4] + modelView[12];
                cubeMatrixGH[5] = G3*modelView[1] + H3*modelView[5] + modelView[13];
                cubeMatrixGH[6] = G4*modelView[0] + H4*modelView[4] + modelView[12];
                cubeMatrixGH[7] = G4*modelView[1] + H4*modelView[5] + modelView[13];
                glBegin(GL_POLYGON);
                glVertex2f(G1,H1);
                glVertex2f(G2,H2);
                glVertex2f(G3,H3);
                glVertex2f(G4,H4);
                glEnd();
              glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
                glutSolidCube(0.5);
            glPopMatrix();



      //object 5(red) // bonus
            glPushMatrix();
                glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
                glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   // COLOR CHANGE
                glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
                glLightfv(GL_LIGHT0, GL_POSITION, object_Light_pos);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_red);
                glTranslatef(0.0,distance5,0.0);
                glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
                aTorus[0] = A1*modelView[0] + B1*modelView[4] + modelView[12];
                aTorus[1] = A1*modelView[1] + B1*modelView[5] + modelView[13];
                aTorus[2] = A2*modelView[0] + B2*modelView[4] + modelView[12];
                aTorus[3] = A2*modelView[1] + B2*modelView[5] + modelView[13];
                aTorus[4] = A3*modelView[0] + B3*modelView[4] + modelView[12];
                aTorus[5] = A3*modelView[1] + B3*modelView[5] + modelView[13];
                aTorus[6] = A4*modelView[0] + B4*modelView[4] + modelView[12];
                aTorus[7] = A4*modelView[1] + B4*modelView[5] + modelView[13];
                glBegin(GL_POLYGON);
                glVertex2f(A1,B1);
                glVertex2f(A2,B2);
                glVertex2f(A3,B3);
                glVertex2f(A4,B4);
                glEnd();
                glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
                glutSolidSphere(0.4,20,20);
            glPopMatrix();



           // object 6 (bomb)

           glPushMatrix();
            glTranslatef(0.8,distance6,0.0);
            glPushMatrix();
                glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);  // COLOR CHANGE
                glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
              glLightfv(GL_LIGHT0, GL_POSITION, object_Light_pos_black);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffusion_black);

                glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
                cubeMatrixIJ[0] = I1*modelView[0] + J1*modelView[4] + modelView[12];
                cubeMatrixIJ[1] = I1*modelView[1] + J1*modelView[5] + modelView[13];
                cubeMatrixIJ[2] = I2*modelView[0] + J2*modelView[4] + modelView[12];
                cubeMatrixIJ[3] = I2*modelView[1] + J2*modelView[5] + modelView[13];
                cubeMatrixIJ[4] = I3*modelView[0] + J3*modelView[4] + modelView[12];
                cubeMatrixIJ[5] = I3*modelView[1] + J3*modelView[5] + modelView[13];
                cubeMatrixIJ[6] = I4*modelView[0] + J4*modelView[4] + modelView[12];
                cubeMatrixIJ[7] = I4*modelView[1] + J4*modelView[5] + modelView[13];
                /*glBegin(GL_POLYGON);
                glVertex2f(I1,J1);
                glVertex2f(I2,J2);
                glVertex2f(I3,J3);
                glVertex2f(I4,J4);
                glEnd();*/
            glutSolidSphere(0.3,20,20);
            glPopMatrix();
               glPushMatrix();
            glTranslatef(0.0,0.33,0.0);
            glScalef(1.2,0.7,1.0);
            glutSolidCube(0.2);
               glPopMatrix();

               glPushMatrix();
            glTranslatef(0.0,0.38,0.0);
            glScalef(0.8,0.6,1.0);
            glutSolidCube(0.2);
            glPopMatrix();
             glPushMatrix();
            glTranslatef(0.0,0.48,0.0);
            glScalef(0.8,0.6,1.0);
            glRotatef(90,1.0,0.0,0.0);
            glutSolidCone(0.2,0.2,20,20);
            glPopMatrix();

               glPopMatrix();




	}
    glPushMatrix();
        std::ostringstream os;
        os << Score;
       std::string str = os.str();
        std::string score =  "Score : " + str;
        drawText(score.data(), score.size(), 650, 550);
    glPopMatrix();
	glPushMatrix();
        std::string Name;
        if(Time<1000)
            playerName = "Newbie";
        if(Time>=1000 && Time<2500)
            playerName = "Pupil";
        if(Time>=2500)
            playerName = "Specialist";
        Name = "Player Name : " + playerName;
        drawText(Name.data(), Name.size(), 650, 570);
    glPopMatrix();
    glPushMatrix();
        std::ostringstream os1;
         os1 << level;
        std::string stLevel = os1.str();
        std::string Level =  "Level : " + stLevel;
        drawText(Level.data(), Level.size(), 650, 530);
    glPopMatrix();
    glPushMatrix();
        std::ostringstream os2;
         os2 << Time;
        std::string stTime = os2.str();
        std::string time =  "Time : " + stTime;
        drawText(time.data(), time.size(), 650, 510);
    glPopMatrix();
    glPushMatrix();
        std::ostringstream os3;
        cin>>highScore;

         os3 << highScore;
        std::string stHighScore = os3.str();
        std::string text =  "HighScore : " + stHighScore;
        drawText(text.data(), text.size(), 650, 490);
    glPopMatrix();
    glPushMatrix();
        std::string Text =  "Press s to START & Press p to PAUSE ";
        drawText(Text.data(), Text.size(), 300, 570);
    glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char k, int x, int y)
{
    switch (k){
        case 'l':
            up_l=1.0;
            glutTimerFunc(20, update_left, 0);
        break;
        case 'r':
            up_r=1.0;
            glutTimerFunc(20, update_right, 0);
        break;
        case 'p':
            pause_checker=0;
            key=0;


        break;

        case 27:
           exit(0);
        break;

        case 'b':
            glutDisplayFunc(drawScene);
            //flag = false;
        break;

        case 's':
            pause_checker=1;


            if(key==0 && pause_checker==1){

                start=1;
                update_cloud(2);
                update_obj1(2);
                update_obj2(2);
                update_obj3(2);
                update_obj4(2);
                update_obj5(2);
                update_obj6(2);
                key=1;

            }
        break;
    }
}

//Game Over Screen

void myDisplayFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	RenderToDisplay();
	glutSwapBuffers();
}
int Result()
{
    if(Score>=highScore){
        cout<<Score<<endl;

    ifstream stream1("Output.txt");
    ofstream stream2("Input.txt");
    stream2 << stream1.rdbuf();
    }
    flag = true;
    int len;
    strcpy(quote[0], "Hey!!!");
    len = playerName.length();
    for(int i=0;i<len;i++)
        quote[1][i] = playerName[i];
	strcpy(quote[2], "Game Over");
	strcpy(quote[3], "Your Score Is ");
    string T = ToString(Score);
    len = T.length();
    for(int i=0;i<len;i++)
        quote[4][i] = T[i];
    strcpy(quote[5], "Press ESC to EXIT");
	numberOfQuotes = 6;

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(1360, 750);
	glutCreateWindow("Game Result");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLineWidth(3);

	glutDisplayFunc(myDisplayFunction);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(timeTick);
	glutMainLoop();

	return 0;
}



void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        up_l=1.0;
        glutTimerFunc(20, update_left, 0);
    break;
    case GLUT_KEY_RIGHT:
        up_r=1.0;
        glutTimerFunc(20, update_right, 0);
    break;
    }

    glutPostRedisplay();
}

void update(int value) {
	_angle += 4.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 4.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}
    if( pause_checker==1)
        Time+=2;
    //FOR RIGHT SPHERE (blue)//For First Object

    if((Y33>=cubeMatrixEF[1])&& (Y33<=cubeMatrixEF[7])&&(X33>=cubeMatrixEF[0])&&(X33<=cubeMatrixEF[2]) && cnt==0) //1 in low
    {
        cnt = 1;
         glutHideWindow();

        Result();

          flag=0;

    }
    else if((Y22>=cubeMatrixEF[1])&& (Y22<=cubeMatrixEF[7])&&(X22>=cubeMatrixEF[0])&&(X22<=cubeMatrixEF[2]) && cnt==0) //2 in low
     {
         cnt = 1;
         glutHideWindow();
          Result();

         flag=0;

    }
    else if((Y22>=cubeMatrixEF[1])&& (Y22<=cubeMatrixEF[7])&&(X22>=cubeMatrixEF[0])&&(X22<=cubeMatrixEF[2]) && cnt==0) //2 in left
     {
         cnt = 1;
         glutHideWindow();
          Result();

          flag=0;

    }
    else if((X33>=cubeMatrixEF[0])&& (X33<=cubeMatrixEF[2])&&(Y33>=cubeMatrixEF[3])&&(Y33<=cubeMatrixEF[5])&& cnt==0) //1 in right
       {
           cnt = 1;
            glutHideWindow();
            Result();

          flag=0;

    }
    else if((X11>=cubeMatrixEF[0])&& (X11<=cubeMatrixEF[2])&&(Y11>=cubeMatrixEF[3])&&(Y11<=cubeMatrixEF[5]) && cnt==0) //3 in bottom
    {
         cnt = 1;
          glutHideWindow();
          Result();


         flag=0;

    }
    else if((X44>=cubeMatrixEF[0])&& (X44<=cubeMatrixEF[2])&&(Y44>=cubeMatrixEF[3])&&(Y44<=cubeMatrixEF[5]) && cnt==0)//4 in bottom
    {
        cnt = 1;
        glutHideWindow();
        Result();

         flag=0;

    }
     //for Left Sphere(red)//object 1

    if((K44>=cubeMatrixEF[0])&& (K44<=cubeMatrixEF[2])&&(L44>=cubeMatrixEF[1])&&(L44<=cubeMatrixEF[7])&& cnt==0) //1 in low
    {
         cnt = 1;
       glutHideWindow();

         // flag=0;
        Result();
    }
    else if((K11>=cubeMatrixEF[0])&& (K11<=cubeMatrixEF[2])&&(L11>=cubeMatrixEF[1])&&(L11<=cubeMatrixEF[7])&& cnt==0) //2 in bottom
    {
          cnt = 1;
        glutHideWindow();

         // flag=0;
        Result();
    }
    else if((K44>=cubeMatrixEF[0])&& (K44<=cubeMatrixEF[2])&&(L44>=cubeMatrixEF[1])&&(L44<=cubeMatrixEF[7])&& cnt==0) //1 in left
    {
          cnt = 1;
        glutHideWindow();

          //flag=0;
        Result();
    }
    else if((K11>=cubeMatrixEF[0])&& (K11<=cubeMatrixEF[2])&&(L11>=cubeMatrixEF[3])&&(L11<=cubeMatrixEF[5])&& cnt==0) //2 in right
    {
        //exit(0);
        cnt = 1;
       glutHideWindow();
         // flag=0;
        Result();
    }
    else if((K33>=cubeMatrixEF[0])&& (K33<=cubeMatrixEF[2])&&(L33>=cubeMatrixEF[3])&&(L11<=cubeMatrixEF[5])&& cnt==0) //4 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
         // flag=0;
        Result();
    }
    else if((K22>=cubeMatrixEF[0])&& (K22<=cubeMatrixEF[2])&&(L22>=cubeMatrixEF[3])&&(L22<=cubeMatrixEF[5])&& cnt==0) //3 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }

     //FOR RIGHT SPHERE (blue)//Object 2

    if((Y33>=cubeMatrixGH[1])&& (Y33<=cubeMatrixGH[7])&&(X33>=cubeMatrixGH[0])&&(X33<=cubeMatrixGH[2])&& cnt==0) //1 in low
    {
        //exit(0);
        cnt = 1;
        glutHideWindow();
        Result();
    }
    else if((Y22>=cubeMatrixGH[1])&& (Y22<=cubeMatrixGH[7])&&(X22>=cubeMatrixGH[0])&&(X22<=cubeMatrixGH[2])&& cnt==0) //2 in low
    {
        //exit(0);
        cnt = 1;
       glutHideWindow();
        Result();
    }
    else if((Y22>=cubeMatrixGH[1])&& (Y22<=cubeMatrixGH[7])&&(X22>=cubeMatrixGH[0])&&(X22<=cubeMatrixGH[2])&& cnt==0) //2 in left
    {
        //exit(0);
        cnt = 1;
        glutHideWindow();
        Result();
    }
    else if((X33>=cubeMatrixGH[0])&& (X33<=cubeMatrixGH[2])&&(Y33>=cubeMatrixGH[3])&&(Y33<=cubeMatrixGH[5])&& cnt==0 ) //1 in right
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((X11>=cubeMatrixGH[0])&& (X11<=cubeMatrixGH[2])&&(Y11>=cubeMatrixGH[3])&&(Y11<=cubeMatrixGH[5])&& cnt==0) //3 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((X44>=cubeMatrixGH[0])&& (X44<=cubeMatrixGH[2])&&(Y44>=cubeMatrixGH[3])&&(Y44<=cubeMatrixGH[5])&& cnt==0)//4 in bottom
    {
        //exit(0);
        cnt = 1;
        glutHideWindow();
        Result();
    }

     //for Left Sphere(red)//object 2

    if((K44>=cubeMatrixGH[0])&& (K44<=cubeMatrixGH[2])&&(L44>=cubeMatrixGH[1])&&(L44<=cubeMatrixGH[7])&& cnt==0) //1 in low
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K11>=cubeMatrixGH[0])&& (K11<=cubeMatrixGH[2])&&(L11>=cubeMatrixGH[1])&&(L11<=cubeMatrixGH[7])&& cnt==0) //2 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K44>=cubeMatrixGH[0])&& (K44<=cubeMatrixGH[2])&&(L44>=cubeMatrixGH[1])&&(L44<=cubeMatrixGH[7])&& cnt==0) //1 in left
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K11>=cubeMatrixGH[0])&& (K11<=cubeMatrixGH[2])&&(L11>=cubeMatrixGH[3])&&(L11<=cubeMatrixGH[5])&& cnt==0) //2 in right
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K33>=cubeMatrixGH[0])&& (K33<=cubeMatrixGH[2])&&(L33>=cubeMatrixGH[3])&&(L11<=cubeMatrixGH[5])&& cnt==0) //4 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K22>=cubeMatrixGH[0])&& (K22<=cubeMatrixGH[2])&&(L22>=cubeMatrixGH[3])&&(L22<=cubeMatrixGH[5])&&cnt==0) //3 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }



     //FOR RIGHT SPHERE (blue)//Object 4

    if((Y33>=cubeMatrixIJ[1])&& (Y33<=cubeMatrixIJ[7])&&(X33>=cubeMatrixIJ[0])&&(X33<=cubeMatrixIJ[2])&& cnt==0) //1 in low
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((Y22>=cubeMatrixIJ[1])&& (Y22<=cubeMatrixIJ[7])&&(X22>=cubeMatrixIJ[0])&&(X22<=cubeMatrixIJ[2])&& cnt==0) //2 in low
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((Y22>=cubeMatrixIJ[1])&& (Y22<=cubeMatrixIJ[7])&&(X22>=cubeMatrixIJ[0])&&(X22<=cubeMatrixIJ[2])&& cnt==0) //2 in left
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((X33>=cubeMatrixIJ[0])&& (X33<=cubeMatrixIJ[2])&&(Y33>=cubeMatrixIJ[3])&&(Y33<=cubeMatrixIJ[5])&& cnt==0) //1 in right
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((X11>=cubeMatrixIJ[0])&& (X11<=cubeMatrixIJ[2])&&(Y11>=cubeMatrixIJ[3])&&(Y11<=cubeMatrixIJ[5])&& cnt==0) //3 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((X44>=cubeMatrixIJ[0])&& (X44<=cubeMatrixIJ[2])&&(Y44>=cubeMatrixIJ[3])&&(Y44<=cubeMatrixIJ[5])&& cnt==0)//4 in bottom
       {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }

     //for Left Sphere(red)//object 4

    if((K44>=cubeMatrixIJ[0])&& (K44<=cubeMatrixIJ[2])&&(L44>=cubeMatrixIJ[1])&&(L44<=cubeMatrixIJ[7])&& cnt==0) //1 in low
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K11>=cubeMatrixIJ[0])&& (K11<=cubeMatrixIJ[2])&&(L11>=cubeMatrixIJ[1])&&(L11<=cubeMatrixIJ[7])&& cnt==0) //2 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K44>=cubeMatrixIJ[0])&& (K44<=cubeMatrixIJ[2])&&(L44>=cubeMatrixIJ[1])&&(L44<=cubeMatrixIJ[7])&& cnt==0) //1 in left
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K11>=cubeMatrixIJ[0])&& (K11<=cubeMatrixIJ[2])&&(L11>=cubeMatrixIJ[3])&&(L11<=cubeMatrixIJ[5])&& cnt==0) //2 in right
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K33>=cubeMatrixIJ[0])&& (K33<=cubeMatrixIJ[2])&&(L33>=cubeMatrixIJ[3])&&(L11<=cubeMatrixIJ[5]) && cnt==0) //4 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K22>=cubeMatrixIJ[0])&& (K22<=cubeMatrixIJ[2])&&(L22>=cubeMatrixIJ[3])&&(L22<=cubeMatrixIJ[5])&& cnt==0) //3 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }

//FOR RIGHT SPHERE (blue)//Object 6

    if((Y33>=cubeMatrixOP[1])&& (Y33<=cubeMatrixOP[7])&&(X33>=cubeMatrixOP[0])&&(X33<=cubeMatrixOP[2]) && cnt==0) //1 in low
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((Y22>=cubeMatrixOP[1])&& (Y22<=cubeMatrixOP[7])&&(X22>=cubeMatrixOP[0])&&(X22<=cubeMatrixOP[2])&& cnt==0) //2 in low
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((Y22>=cubeMatrixOP[1])&& (Y22<=cubeMatrixOP[7])&&(X22>=cubeMatrixOP[0])&&(X22<=cubeMatrixOP[2])&& cnt==0) //2 in left
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((X33>=cubeMatrixOP[0])&& (X33<=cubeMatrixOP[2])&&(Y33>=cubeMatrixOP[3])&&(Y33<=cubeMatrixOP[5])&& cnt==0) //1 in right
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((X11>=cubeMatrixOP[0])&& (X11<=cubeMatrixOP[2])&&(Y11>=cubeMatrixOP[3])&&(Y11<=cubeMatrixOP[5]) && cnt==0) //3 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((X44>=cubeMatrixOP[0])&& (X44<=cubeMatrixOP[2])&&(Y44>=cubeMatrixOP[3])&&(Y44<=cubeMatrixOP[5])&& cnt==0)//4 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }

     //for Left Sphere(red)//object 6

    if((K44>=cubeMatrixOP[0])&& (K44<=cubeMatrixOP[2])&&(L44>=cubeMatrixOP[1])&&(L44<=cubeMatrixOP[7])&& cnt==0) //1 in low
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K11>=cubeMatrixOP[0])&& (K11<=cubeMatrixOP[2])&&(L11>=cubeMatrixOP[1])&&(L11<=cubeMatrixOP[7])&& cnt==0) //2 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K44>=cubeMatrixOP[0])&& (K44<=cubeMatrixOP[2])&&(L44>=cubeMatrixOP[1])&&(L44<=cubeMatrixOP[7])&& cnt==0) //1 in left
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K11>=cubeMatrixOP[0])&& (K11<=cubeMatrixOP[2])&&(L11>=cubeMatrixOP[3])&&(L11<=cubeMatrixOP[5])&& cnt==0) //2 in right
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K33>=cubeMatrixOP[0])&& (K33<=cubeMatrixOP[2])&&(L33>=cubeMatrixOP[3])&&(L11<=cubeMatrixOP[5]) && cnt==0) //4 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }
    else if((K22>=cubeMatrixOP[0])&& (K22<=cubeMatrixOP[2])&&(L22>=cubeMatrixOP[3])&&(L22<=cubeMatrixOP[5]) && cnt==0) //3 in bottom
    {
        //exit(0);
        cnt = 1;
         glutHideWindow();
        Result();
    }


    //FOR RIGHT SPHERE (blue)/ object 5
    if((Y33>=aTorus[1])&& (Y33<=aTorus[7])&&(X33>=aTorus[0])&&(X33<=aTorus[2])) //1 in low
     {
        sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
        checkTouch = 1;
     }
    else if((Y22>=aTorus[1])&& (Y22<=aTorus[7])&&(X22>=aTorus[0])&&(X22<=aTorus[2])) //2 in low
    {
        sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
        checkTouch = 1;
     }
    else if((Y22>=aTorus[1])&& (Y22<=aTorus[7])&&(X22>=aTorus[0])&&(X22<=aTorus[2])) //2 in left
    {
        sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
        checkTouch = 1;
     }
    else if((X33>=aTorus[0])&& (X33<=aTorus[2])&&(Y33>=aTorus[3])&&(Y33<=aTorus[5])) //1 in right
    {
        sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
        checkTouch = 1;
     }
    else if((X11>=aTorus[0])&& (X11<=aTorus[2])&&(Y11>=aTorus[3])&&(Y11<=aTorus[5])) //3 in bottom
    {
        sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
        checkTouch = 1;
     }
    else if((X44>=aTorus[0])&& (X44<=aTorus[2])&&(Y44>=aTorus[3])&&(Y44<=aTorus[5]))//4 in bottom
    {
        sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
        checkTouch = 1;
     }
//for Left Sphere(red)//object 5

    if((K44>=aTorus[0])&& (K44<=aTorus[2])&&(L44>=aTorus[1])&&(L44<=aTorus[7])) //1 in low
        checkTouch = 2;
    else if((K11>=aTorus[0])&& (K11<=aTorus[2])&&(L11>=aTorus[1])&&(L11<=aTorus[7])) //2 in bottom
        checkTouch = 2;
    else if((K44>=aTorus[0])&& (K44<=aTorus[2])&&(L44>=aTorus[1])&&(L44<=aTorus[7])) //1 in left
        checkTouch = 2;
    else if((K11>=aTorus[0])&& (K11<=aTorus[2])&&(L11>=aTorus[3])&&(L11<=aTorus[5])) //2 in right
        checkTouch = 2;
    else if((K33>=aTorus[0])&& (K33<=aTorus[2])&&(L33>=aTorus[3])&&(L11<=aTorus[5])) //4 in bottom
        checkTouch = 2;
    else if((K22>=aTorus[0])&& (K22<=aTorus[2])&&(L22>=aTorus[3])&&(L22<=aTorus[5])) //3 in bottom
        checkTouch = 2;

   //FOR RIGHT SPHERE (blue)/ object 3(blue)
    if((Y33>=bTorus[1])&& (Y33<=bTorus[7])&&(X33>=bTorus[0])&&(X33<=bTorus[2])) //1 in low
        checkTouch = 2;
    else if((Y22>=bTorus[1])&& (Y22<=bTorus[7])&&(X22>=bTorus[0])&&(X22<=bTorus[2])) //2 in low
        checkTouch = 2;
    else if((Y22>=bTorus[1])&& (Y22<=bTorus[7])&&(X22>=bTorus[0])&&(X22<=bTorus[2])) //2 in left
        checkTouch = 2;
    else if((X33>=bTorus[0])&& (X33<=bTorus[2])&&(Y33>=bTorus[3])&&(Y33<=bTorus[5])) //1 in right
        checkTouch = 2;
    else if((X11>=bTorus[0])&& (X11<=bTorus[2])&&(Y11>=bTorus[3])&&(Y11<=bTorus[5])) //3 in bottom
        checkTouch = 2;
    else if((X44>=bTorus[0])&& (X44<=bTorus[2])&&(Y44>=bTorus[3])&&(Y44<=bTorus[5])) //4 in bottom
        checkTouch = 2;


//for Left Sphere(red)//object 3(blue)



    if((K44>=bTorus[0])&& (K44<=bTorus[2])&&(L44>=bTorus[1])&&(L44<=bTorus[7])) //1 in low
    {
         sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
         checkTouch = 1;
    }
    else if((K11>=bTorus[0])&& (K11<=bTorus[2])&&(L11>=bTorus[1])&&(L11<=bTorus[7])) //2 in bottom
    {
         sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
         checkTouch = 1;
    }
    else if((K44>=bTorus[0])&& (K44<=bTorus[2])&&(L44>=bTorus[1])&&(L44<=bTorus[7])) //1 in left
    {
         sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
         checkTouch = 1;
    }
    else if((K11>=bTorus[0])&& (K11<=bTorus[2])&&(L11>=bTorus[3])&&(L11<=bTorus[5])) //2 in right
    {
         sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
         checkTouch = 1;
    }
    else if((K33>=bTorus[0])&& (K33<=bTorus[2])&&(L33>=bTorus[3])&&(L11<=bTorus[5])) //4 in bottom
    {
         sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
         checkTouch = 1;
    }
    else if((K22>=bTorus[0])&& (K22<=bTorus[2])&&(L22>=bTorus[3])&&(L22<=bTorus[5])) //3 in bottom
    {
         sndPlaySound("sound Happy-electronic-music.wav",SND_ASYNC);
         checkTouch = 1;
    }

    glutPostRedisplay(); //Tell GLUT that the display has changed
	//Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(20, update, 0);
}
void update_left(int value) {
     if(up_l==1.0)
     {
        angle += 20.0f;

     }
     glutPostRedisplay();
	 //glutTimerFunc(20, update_left, 0);
	 up_l=0.0;


}

void update_right(int value) {
    if(up_r==1.0){
        angle -= 20.0f;
    }
    glutPostRedisplay();
    //glutTimerFunc(20, update_left, 0);
    up_r=0.0;
}

void update_obj1(int value){
    if(pause_checker==1){
    if(distance1 >= -3.5){
        distance1-=0.03;
    }
    if(distance1 < -3.5 ){
             ++Score;
        distance1=12.0;
    }

    glutTimerFunc(20, update_obj1, 0);
    glutPostRedisplay();
    }
    else if(pause_checker==0){
             glutPostRedisplay();

    }
}

void update_obj2(int value){
    if(pause_checker==1){
    if(distance2 >= -3.5){
        distance2-=0.03;
    }
    if(distance2< -3.5 ){
             ++Score;
        distance2=12.0;
    }
  //  if(distance2==10)
       // ++Score;
    glutTimerFunc(20, update_obj2, 0);
    glutPostRedisplay();
    }
    else if(pause_checker==0){
        glutPostRedisplay();
    }
}


void update_obj3(int value){
    if(pause_checker==1)
    {
    if(distance3 >= -3.5){
        distance3-=0.03;
    }
    if(distance3< -3.5)
    {
         ++Score;
        distance3=12.0;
    }
   // if(distance3==16)
     //   ++Score;
    glutTimerFunc(20, update_obj3, 0);
    glutPostRedisplay();
    }
    else if(pause_checker==0)
    {
         glutPostRedisplay();
    }
}

void update_obj4(int value){
    if(pause_checker==1)
    {
    if(distance4 >= -3.5){
        distance4-=0.03;
    }
    if(distance4 < -3.5 ){
             ++Score;
        distance4=12.0;
    }
    glutTimerFunc(20, update_obj4, 0);
    glutPostRedisplay();
    }
    else if(pause_checker==0)
    {
        glutPostRedisplay();
    }
}

void update_obj5(int value){
    if(pause_checker==1){
    if(distance5 >= -3.5){
        distance5-=0.03;
    }
    if(distance5 < -3.5 ){
             ++Score;
        distance5=12.0;
    }
    glutTimerFunc(20, update_obj5, 0);
    glutPostRedisplay();
    }
    else if(pause_checker==0)
    {
          glutPostRedisplay();
    }
}

void update_obj6(int value){
    if(pause_checker==1){
    if(distance6 >= -3.5){
        distance6-=0.03;
    }
    if(distance6 < -3.5 ){
             ++Score;
        distance6=12.0;
    }
    glutTimerFunc(20, update_obj6, 0);
    glutPostRedisplay();
    }
    else if(pause_checker==0)
    {
       glutPostRedisplay();
    }
}

void update_cloud(int value){
    distance_cloud+=0.1;
if(distance_cloud >20){
        distance_cloud-=45.0;
}

glutTimerFunc(20, update_cloud, 0);
    glutPostRedisplay();

}


int main(int argc, char** argv) {

    READ();
    WRITE();
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1350, 700);
   // glutPositionWindow(glutGet(GLUT_WINDOW_X),glutGet(GLUT_WINDOW_Y));
   // glutFullScreen();
	//Create the window
	glutCreateWindow("SWINGER MATCH");
	initRendering();
	//Set handler functions

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(keyboard);
   /* */
    glutSpecialFunc(SpecialInput);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0);
    //Add a timer
	glutMainLoop();
	return 0;
}







