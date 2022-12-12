#include<bits/stdc++.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include<GL/gl.h>
#include<cstdio>
#include<time.h>

# define PI           3.14159265358979323846
using namespace std;
bool stop = 1;                   ///declare variable
bool temp =0;
bool rainday = false;             ///initialy false jno bristy na hoy
GLfloat j = 0.0f;
GLfloat k = 0.0f;
GLfloat l = 0.0f;
GLfloat e = 0.0f;
float _move2= 0.0;
float _move = 0.0;
float _move1=0.0;   /// translate variable for moving
float _move3=0.0;
float _move4=0.0;
float _move5=0.0;
float _move6=0.0;




void night(int n);    /// night function
void night1();


GLfloat q = 0.0f;
GLfloat position =0.0f;
GLfloat position2=0.0f;
GLfloat position3=0.0f;
GLfloat speed = 0.009f;

int r = 0;   /// sun rotate

void init() {                  ///putting the system into graphics mode
    glClearColor(0.0f,0.0f,0.0f,1.0f);  /// set back ground color
    glClear(GL_COLOR_BUFFER_BIT);      /// glClear to clear the color buffers
    glLineWidth(2);            ///line koto mota
}

void update(int value) {
    if(position > 1.0)
        position = -1.0f;

    position += speed;     ///used for movement purpose  (CLOUD,BIRD and PLANE)

    glutPostRedisplay();

    glutTimerFunc(100, update, 0);   ///registers a timer callback to be triggered in a specified number of milliseconds
}


void update2(int value){

    _move +=0.005f;
    if(_move-1.966 > 1.0)
    {
        _move = -1.0;
    }

    _move1 +=0.002f;
    if(_move1-1.993 > 1.0)    /// (CAR and BUS) moving
    {
        _move1 = -1.0;
    }

    if(stop==1)
    {
        _move2 -=0.01f;
        if(_move2+1.5 < -1.0)
        {
            _move2 = 1.0;
        }

    }


    _move3 -=0.01f;
    if(_move3+1.966 < -1.0)
    {
        _move3 = 1.0;
    }

    _move4 +=0.0005f;
    if(_move4-1.39 > 1.0)
    {
        _move4 = -1.4;
    }

    _move5 +=0.0006f;
    if(_move5-0.79>1.0)
    {
        _move5 = -1.4;
    }


    _move6 +=0.01f;
    if(_move6-1.663 > 1.0)
    {
        _move6 = -1.0;
    }

    glutPostRedisplay();

    glutTimerFunc(25, update2, 0);
}


                                  /// It draws the sky
void sky() { /// SUMYA
    glBegin(GL_QUADS);              /// glBegin specifies the type of geometric object
    glColor3ub(98, 154, 214);        /// such as GL_POINTS , GL_LINES , GL_QUADS ,

    glVertex2f(-1.0f, -1.0f);       /// squad er vertex 4 ta thke
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);

    glEnd();                           ///The glBegin and glEnd functions delimit the vertices
                                        ///that define a primitive or a group of like primitives
}


void nightSky() { ///SUMYA
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);              ///color

    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);

    glEnd();
}


void cloud() { /// SUMYA

    glPushMatrix();        ///pushes the current matrix stack down by one, duplicating the current matrix.
    glTranslatef(position,0.0,0.0);
    int i;

	GLfloat x=.5f; GLfloat y=.8f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * 3.1416;

	glBegin(GL_TRIANGLE_FAN);      /// Gl_TRIANGLE_FAN can be used for drawing filled-in polygons
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), ///vertex er angular value
			       y + (radius * sin(i * twicePi / triangleAmount)));
    }

	glEnd();

	GLfloat a=.55f; GLfloat b=.78f;

	glBegin(GL_TRIANGLE_FAN);  ///fill kora
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(a + (radius * cos(i *  twicePi / triangleAmount)),
                   b + (radius * sin(i * twicePi / triangleAmount)));
    }

	glEnd();

	GLfloat c=.45f; GLfloat d=.78f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(c + (radius * cos(i *  twicePi / triangleAmount)),
                   d + (radius * sin(i * twicePi / triangleAmount)));
    }
	glEnd();

	GLfloat e=.52f; GLfloat f=.75f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(e + (radius * cos(i *  twicePi / triangleAmount)),
                   f + (radius * sin(i * twicePi / triangleAmount)));
    }

	glEnd();

	GLfloat g=.6f; GLfloat h=.77f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(g + (radius * cos(i *  twicePi / triangleAmount)),
                   h + (radius * sin(i * twicePi / triangleAmount)));
    }
	glEnd();

    glPopMatrix();  ///same as glEND glPopMatrix pops the top matrix off the stack.
}

void cloud2() ///SUMYA
{
    glPushMatrix();
    glTranslatef(position,0.0,0.0);
    int i;

	GLfloat x=.5f; GLfloat y=.8f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * 3.1416;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)),
			       y + (radius * sin(i * twicePi / triangleAmount)));
    }

	glEnd();

	GLfloat a=.55f; GLfloat b=.78f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(a + (radius * cos(i *  twicePi / triangleAmount)),
                   b + (radius * sin(i * twicePi / triangleAmount)));
    }

	glEnd();

	GLfloat c=.45f; GLfloat d=.78f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(c + (radius * cos(i *  twicePi / triangleAmount)), ///for curve of cloud
                   d + (radius * sin(i * twicePi / triangleAmount)));
    }
	glEnd();

	GLfloat e=.52f; GLfloat f=.75f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(e + (radius * cos(i *  twicePi / triangleAmount)),
                   f + (radius * sin(i * twicePi / triangleAmount)));
    }

	glEnd();

	GLfloat g=.6f; GLfloat h=.77f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(g + (radius * cos(i *  twicePi / triangleAmount)),
                   h + (radius * sin(i * twicePi / triangleAmount)));
    }
	glEnd();
	glPopMatrix();
}

void bird() { /// SADIA

    glPushMatrix();
    glTranslatef(position,0.0,0.0);   ///Translate kore (X,Y,Z)

    glBegin(GL_LINES);

    glColor3ub(255, 255, 255);

    glVertex2f(0.2f, 0.8f);
    glVertex2f(0.18f, 0.77f);

    glVertex2f(0.18f, 0.77f);
    glVertex2f(0.15f, 0.79f);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);

    glVertex2f(-0.1f, 0.8f);
    glVertex2f(-0.13f, 0.77f);

    glVertex2f(-0.13f, 0.77f);
    glVertex2f(-0.15f, 0.8f);
    glEnd();

    glPopMatrix();
}

void memorial() {  /// MINHAJUL
    glBegin(GL_TRIANGLES);
    glColor3ub(166, 166, 166);

    glVertex2f(-0.01f, 0.7f);
    glVertex2f(0.01f, 0.7f);
    glVertex2f(0.0f, 0.75f);

    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(204, 204, 204);

    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.0f, 0.7f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(150, 40, 27);

    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.0f, 0.0f);

    glEnd();

	glBegin(GL_QUADS);
	glColor3ub(128, 128, 128);

	glVertex2f(0.0f, 0.0f);
	glVertex2d(0.125f, 0.2f);
	glVertex2f(0.0f, 0.4f);
	glVertex2f(-0.125f, 0.2f);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(166, 166, 166);

	glVertex2f(-0.115f, 0.215f);
	glVertex2f(-0.125f, 0.2f);
	glVertex2f(-0.115f, 0.185f);
	glVertex2f(0.115f, 0.185f);
	glVertex2f(0.125f, 0.2f);
	glVertex2f(0.115f, 0.215f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(0.2f, -0.1f);
	glVertex2f(0.21f, -0.1f);
	glVertex2f(0.01f, 0.7f);
	glVertex2f(0.00f, 0.7f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(-0.2f, -0.1f);
	glVertex2f(-0.21f, -0.1f);
	glVertex2f(-0.01f, 0.7f);
	glVertex2f(-0.00f, 0.7f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(0.21f, -0.1f);
	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.06f, 0.5f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(-0.21f, -0.1f);
	glVertex2f(-0.3f, -0.1f);
	glVertex2f(-0.06f, 0.5f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.31f, -0.1f);
	glVertex2f(0.055f, 0.52f);
	glVertex2f(0.054f, 0.5f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(-0.3f, -0.1f);
	glVertex2f(-0.31f, -0.1f);
	glVertex2f(-0.055f, 0.52f);
	glVertex2f(-0.054f, 0.5f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(0.31f, -0.1f);
	glVertex2f(0.4f, -0.1f);
	glVertex2f(0.1f, 0.4f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(-0.31f, -0.1f);
	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.1f, 0.4f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(0.4f, -0.1f);
	glVertex2f(0.41f, -0.1f);
	glVertex2f(0.095f, 0.42f);
	glVertex2f(0.1f, 0.4f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.41f, -0.1f);
	glVertex2f(-0.095f, 0.42f);
	glVertex2f(-0.1f, 0.4f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(0.41f, -0.1f);
	glVertex2f(0.5f, -0.1f);
	glVertex2f(0.167f, 0.3f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(-0.41f, -0.1f);
	glVertex2f(-0.5f, -0.1f);
	glVertex2f(-0.167f, 0.3f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(0.5f, -0.1f);
	glVertex2f(0.51f, -0.1f);
	glVertex2f(0.1568f, 0.316f);
	glVertex2f(0.16f, 0.3f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(-0.5f, -0.1f);
	glVertex2f(-0.51f, -0.1f);
	glVertex2f(-0.1568f, 0.316f);
	glVertex2f(-0.16f, 0.3f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(0.51f, -0.1f);
	glVertex2f(0.6f, -0.1f);
	glVertex2f(0.17f, 0.3f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(-0.51f, -0.1f);
	glVertex2f(-0.6f, -0.1f);
	glVertex2f(-0.17f, 0.3f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(0.6f, -0.1f);
	glVertex2f(0.615f, -0.1f);
	glVertex2f(0.15f, 0.33f);
	glVertex2f(0.167f, 0.3f);

	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(-0.6f, -0.1f);
	glVertex2f(-0.615f, -0.1f);
	glVertex2f(-0.15f, 0.33f);
	glVertex2f(-0.167f, 0.3f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(0.61f, -0.1f);
	glVertex2f(0.7f, -0.1f);
	glVertex2f(0.29f, 0.2f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(-0.61f, -0.1f);
	glVertex2f(-0.7f, -0.1f);
	glVertex2f(-0.29f, 0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(0.7f, -0.1f);
	glVertex2f(0.718f, -0.1f);
	glVertex2f(0.25f, 0.24f);
	glVertex2f(0.275f, 0.21f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(-0.7f, -0.1f);
	glVertex2f(-0.718f, -0.1f);
	glVertex2f(-0.25f, 0.24f);
	glVertex2f(-0.275f, 0.21f);

	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3ub(204, 204, 204);

	glVertex2f(0.71f, -0.1f);
    glVertex2f(0.8f, -0.1f);
    glVertex2f(0.3f, 0.2f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3ub(204, 204, 204);
	glVertex2f(-0.71f, -0.1f);
    glVertex2f(-0.8f, -0.1f);
    glVertex2f(-0.3f, 0.2f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3ub(230, 230, 230);
	glVertex2f(0.8f,-0.1f);
    glVertex2f(0.82f, -0.1f);
    glVertex2f(0.25f,0.241f);
    glVertex2f(0.265f, 0.221f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);

	glVertex2f(-0.8f,-0.1f);
    glVertex2f(-0.82f, -0.1f);
    glVertex2f(-0.25f,0.241f);
    glVertex2f(-0.265f, 0.221f);

	glEnd();
}

void stairs() { /// MINHAJUL
    glBegin(GL_QUADS);
    glColor3ub(150, 40, 27);             /// put random value for color change
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -0.1f);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);              /// line mota chikon kora
    glColor3ub(0, 0, 0);

    glVertex2f(-1.0f, -0.13f);
    glVertex2f(1.0f, -0.13f);

    glVertex2f(-1.0f, -0.16f);
    glVertex2f(1.0f, -0.16f);

    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);

    glVertex2f(-1.0f, -0.23f);
    glVertex2f(1.0f, -0.23f);

    glVertex2f(-1.0f, -0.26f);
    glVertex2f(1.0f, -0.26f);

    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);

    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);

    glEnd();
}

void field() { /// SADIA
    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);

    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();
}

void pool() ///MINHAJUL
 {


    glBegin(GL_QUADS);
    glColor3ub(0, 102, 255);

    glVertex2f(-0.3f, -0.4f);
    glVertex2f(0.3f, -0.4f);
    glVertex2f(0.4f, -1.0f);
    glVertex2f(-0.4f, -1.0f);

    glEnd();
}
void borderPool() /// SADIA
{

    glBegin(GL_QUADS);
    glColor3ub(217, 217, 217);

    glVertex2f(-0.4f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.5f, -1.0f);
    glVertex2f(-0.5f, -1.0f);

    glEnd();
}

void flag() { ///SADIA
    glPushMatrix();               ///same as glBegin kaj kore
    glTranslatef(0.09,0.0,0.0);  ///produces the translation specified by (x, y, z)

    glBegin(GL_QUADS);
    glColor3ub(150, 40, 27);

    glVertex2f(-0.1f, -1.0f);
    glVertex2f(0.1f, -1.0f);
    glVertex2f(0.05f, -0.9f);
    glVertex2f(-0.05f, -0.9f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);

    glVertex2f(-0.01f, -1.0f);
    glVertex2f(0.01f, -1.0f);
    glVertex2f(0.01f, 0.05f);
    glVertex2f(-0.01f, 0.05f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 153, 51);

    glVertex2f(0.01f, 0.05f);
    glVertex2f(0.37f, 0.05f);
    glVertex2f(0.37f, -0.2f);
    glVertex2f(0.01f, -0.2f);

    glEnd();

    float x = 0.19f, y = -0.07f, r = 0.07;
    float twicePie = 2.0 * 3.1416;
    int trainglePoints = 20;

    glBegin(GL_TRIANGLE_FAN);   ///Gl_TRIANGLE_FAN can be used for drawing filled-in polygons
    glColor3ub(255, 0, 0);

    for(int i = 0; i<=trainglePoints; i++) {
        glVertex2f(x + r * cos(i * twicePie / trainglePoints),
                   y + r * sin(i * twicePie / trainglePoints));
    }

    glEnd();
    glPopMatrix();
}

void road() { ///SADIA

    glLoadIdentity();   ///parameters are not combined with the previous one
	glMatrixMode(GL_MODELVIEW);   ///sets the current matrix mode jno gari thik thake
	glPushMatrix();
    glTranslatef(0,-.7,0);    ///position
      glBegin(GL_POLYGON);
      glColor3f(0.698, 0.745, 0.7098);
      glVertex3f(-1.0f, -0.33f, 0.0f);
      glVertex3f(1.0f, -0.33f, 0.0f);
      glVertex3f(1.0f, 0.0f, 0.0f);
      glVertex3f(-1.0f, 0.0f, 0.0f);

/// Roadline
      glBegin(GL_QUADS);
      glColor3f(1.0, 1.0, 1.0);
      glVertex3f(-0.33f, -0.166f, 0.0f);
      glVertex3f(-0.166f, -0.166f, 0.0f);
      glVertex3f(-0.166f, -0.13f, 0.0f);
      glVertex3f(-0.33f, -0.13f, 0.0f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0, 1.0, 1.0);
      glVertex3f(0.33f, -0.166f, 0.0f);
      glVertex3f(0.833f, -0.166f, 0.0f);
      glVertex3f(0.833f, -0.13f, 0.0f);
      glVertex3f(0.33f, -0.13f, 0.0f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0, 1.0, 1.0);
      glVertex3f(0.833f, -0.166f, 0.0f);
      glVertex3f(1.0f, -0.166f, 0.0f);
      glVertex3f(1.0f, -0.13f, 0.0f);
      glVertex3f(0.833f, -0.13f, 0.0f);
      glEnd();
      glPopMatrix();

}

void tree(){ /// SUMYA
    glLoadIdentity();   ///current matrix k replace kore
	glMatrixMode(GL_MODELVIEW); ///akter opor arekta dekha jabe
	glPushMatrix();
	glTranslated(0.6,0.05,0);
	glScalef(.4,.5,0);   ///produces a general scaling along the x, y, and z axes.


    glBegin(GL_POLYGON);
    glColor3f(0.6,0.298,0.0);
    glVertex3f(-0.1f,-0.33f,0.0f);
    glVertex3f(-0.066f,-0.33f,0.0f);
    glVertex3f(-0.066f,0.166f,0.0f);
    glVertex3f(-0.1f,0.166f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.298,0.0);
    glVertex3f(0.4f,-0.33f,0.0f);
    glVertex3f(0.433f,-0.33f,0.0f);
    glVertex3f(0.433f,0.166f,0.0f);
    glVertex3f(0.4f,0.166f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.298,0.0);
    glVertex3f(0.9f,-0.33f,0.0f);
    glVertex3f(0.933f,-0.33f,0.0f);
    glVertex3f(0.933f,0.166f,0.0f);
    glVertex3f(0.9f,0.166f,0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.4,0.0);
    glVertex3f(-0.15f,-0.166f,0.0f);
    glVertex3f(-0.016f,-0.166f,0.0f);
    glVertex3f(-0.0833f,-0.0f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.4,0.0);
    glVertex3f(0.35f,-0.166f,0.0f);
    glVertex3f(0.483f,-0.166f,0.0f);
    glVertex3f(0.4166f,0.0f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.4,0.0);
    glVertex3f(0.85f,-0.166f,0.0f);
    glVertex3f(0.983f,-0.166f,0.0f);
    glVertex3f(0.9166f,0.0f,0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(-0.15f,-0.05f,0.0f);
    glVertex3f(-0.016f,-0.05f,0.0f);
    glVertex3f(-0.0833f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.35f,-0.05f,0.0f);
    glVertex3f(0.483f,-0.05f,0.0f);
    glVertex3f(0.4166f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.85f,-0.05f,0.0f);
    glVertex3f(0.983f,-0.05f,0.0f);
    glVertex3f(0.9166f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.85f,-0.05f,0.0f);
    glVertex3f(0.983f,-0.05f,0.0f);
    glVertex3f(0.9166f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.85f,-0.05f,0.0f);
    glVertex3f(0.983f,-0.05f,0.0f);
    glVertex3f(0.9166f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.85f,-0.05f,0.0f);
    glVertex3f(0.983f,-0.05f,0.0f);
    glVertex3f(0.9166f,0.33f,0.0f);
    glEnd();

    glPopMatrix();
}
void tree2(){  ///SUMYA
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(-1,0.05,0);
	glScalef(.4,.5,0);

    glBegin(GL_POLYGON);
    glColor3f(0.6,0.298,0.0);
    glVertex3f(-0.1f,-0.33f,0.0f);
    glVertex3f(-0.066f,-0.33f,0.0f);
    glVertex3f(-0.066f,0.166f,0.0f);
    glVertex3f(-0.1f,0.166f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.298,0.0);
    glVertex3f(0.4f,-0.33f,0.0f);
    glVertex3f(0.433f,-0.33f,0.0f);
    glVertex3f(0.433f,0.166f,0.0f);
    glVertex3f(0.4f,0.166f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.298,0.0);
    glVertex3f(0.9f,-0.33f,0.0f);
    glVertex3f(0.933f,-0.33f,0.0f);
    glVertex3f(0.933f,0.166f,0.0f);
    glVertex3f(0.9f,0.166f,0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.4,0.0);
    glVertex3f(-0.15f,-0.166f,0.0f);
    glVertex3f(-0.016f,-0.166f,0.0f);
    glVertex3f(-0.0833f,-0.0f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.4,0.0);
    glVertex3f(0.35f,-0.166f,0.0f);
    glVertex3f(0.483f,-0.166f,0.0f);
    glVertex3f(0.4166f,0.0f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.4,0.0);
    glVertex3f(0.85f,-0.166f,0.0f);
    glVertex3f(0.983f,-0.166f,0.0f);
    glVertex3f(0.9166f,0.0f,0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(-0.15f,-0.05f,0.0f);
    glVertex3f(-0.016f,-0.05f,0.0f);
    glVertex3f(-0.0833f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.35f,-0.05f,0.0f);
    glVertex3f(0.483f,-0.05f,0.0f);
    glVertex3f(0.4166f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.85f,-0.05f,0.0f);
    glVertex3f(0.983f,-0.05f,0.0f);
    glVertex3f(0.9166f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.85f,-0.05f,0.0f);
    glVertex3f(0.983f,-0.05f,0.0f);
    glVertex3f(0.9166f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.85f,-0.05f,0.0f);
    glVertex3f(0.983f,-0.05f,0.0f);
    glVertex3f(0.9166f,0.33f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.8,0.0);
    glVertex3f(0.85f,-0.05f,0.0f);
    glVertex3f(0.983f,-0.05f,0.0f);
    glVertex3f(0.9166f,0.33f,0.0f);
    glEnd();

    glPopMatrix();
}


void rain(){ /// MINHAJUL
    glColor3f(1,1,1);  ///white rain
    if(temp)
    {
    for(float i=-10; i<1; i+=.1)
    {

        float r=rand()%50;
        float r2=rand()%50;  /// random func
        float r3=rand()%50;
        float r4=rand()%50;

        r=(r/50);
        r2=r2/50;
        r3=r3/50;
        r4=r4/50;

        glLineWidth(1);
        glBegin(GL_LINES);

        glVertex2f(0+r,.04+r2);
        glVertex2f(0+r,0+r2);

        glVertex2f(0+r4,.04-r2);
        glVertex2f(0+r4,0-r2);

        glVertex2f(0-r2,.04-r3);
        glVertex2f(0-r2,0-r3);

        glVertex2f(0-r3,.04+r4);
        glVertex2f(0-r3,0+r4);

        glEnd();
    }
    }
}


void line(GLfloat b1,GLfloat b2,GLfloat b3,GLfloat b4,GLubyte R,GLubyte G,GLubyte B){    ///joto ber lagbe use korsi
    glBegin(GL_LINES);
    glColor3ub(R,G,B);
    glVertex2f(b1,b2);
    glVertex2f(b3,b4);
    glEnd();
}
void circle(GLfloat X,GLfloat Y,GLfloat R,GLubyte r,GLubyte g,GLubyte b){ ///joto ber lagbe use korsi
    int i;
    GLfloat x=X; GLfloat y=Y; GLfloat radius =R;
	int triangleAmount = 50;

    GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);          ///poligon er fill kortisi
	glColor3ub(r,g,b);

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(

                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

}

void sun(){///SUMYA
    glTranslatef(.75,.85,0);
    glPushMatrix();
    glRotatef(e,0.0,0.0,0.30);


    line(0,0,0,.15,255, 255, 179);
    line(0,0,0,-.15,255, 255, 179);
    line(0,0,0.15,0,255, 255, 179);
    line(0,0,-0.15,0,255, 255, 179);
    line(0,0,0.10,.10,255, 255, 179);
    line(0,0,0.10,-0.10,255, 255, 179);
    line(0,0,-0.10,.10,255, 255, 179);
    line(0,0,-0.10,-.10,255, 255, 179);
    glPopMatrix();
    e-=5.5f;
    glLoadIdentity();
    circle(.75,.85,.1,255, 255, 0);

}
void moon(){///SUMYA
    circle(.75,.85,-.1,255, 255, 255);

}

void _star(float x=0,float y=0,float _size=1)/// MINHAJUL
{
    glPointSize(3);
    glLoadIdentity(); ///Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(x,y,0);
    glScalef(_size,_size,0);

    glBegin(GL_QUADS);
    glColor3f(1,1,0);

    glVertex2f(.1,0);
    glVertex2f(.12,.1);
    glVertex2f(.1,.2);
    glVertex2f(.08,.1);

    glVertex2f(0,.1);
    glVertex2f(.1,.12);
    glVertex2f(.2,.1);
    glVertex2f(.1,.08);
    glEnd();
    glPopMatrix();
}



void manyStar(float x=0,float y=0,float z=1)
{
    _star(.1+x,.3+y,.2*z);
    _star(.08+x,.34+y,.2*z);
    _star(.2+x,.32+y,.2*z);
    _star(.25+x,.31+y,.2*z);
    _star(.13+x,.4+y,.2*z);
    _star(.15+x,.35+y,.2*z);
    _star(.22+x,.38+y,.2*z);
    _star(.2+x,.38+y,.12*z);
    _star(.27+x,.35+y,.12*z);
    _star(.14+x,.3+y,.12*z);
}
void bus()///SUMYA
{
    glPushMatrix();
    glTranslatef(_move2+0.3, -0.7f, 0.0f);
    glScalef(0.7,0.6,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0, 0.0);
    glVertex3f(0.5f, -0.166f, 0.0f);
    glVertex3f(1.0f, -0.166f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.55f, 0.0f, 0.0f);
    glVertex3f(0.5f, -0.033f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0, 0.0);
    glVertex3f(0.5f, -0.1f, 0.0f);
    glVertex3f(0.5166f, -0.1f, 0.0f);
    glVertex3f(0.5166f, -0.066f, 0.0f);
    glVertex3f(0.5f, -0.066f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0, 0.0);
    glVertex3f(0.55f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.116f, 0.0f);
    glVertex3f(0.55f, 0.116f, 0.0f);
    glEnd();

    ///BusWindows
    glBegin(GL_POLYGON);
    glColor3f(0.26,0.26, 0.26);
    glVertex3f(0.5833f, 0.016f, 0.0f);
    glVertex3f(0.633f, 0.016f, 0.0f);
    glVertex3f(0.633f, 0.1f, 0.0f);
    glVertex3f(0.5833f, 0.1f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.26,0.26, 0.26);
    glVertex3f(0.65f, 0.016f, 0.0f);
    glVertex3f(0.7f, 0.016f, 0.0f);
    glVertex3f(0.7f, 0.1f, 0.0f);
    glVertex3f(0.65f, 0.1f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.26,0.26, 0.26);
    glVertex3f(0.716f, 0.016f, 0.0f);
    glVertex3f(0.766f, 0.016f, 0.0f);
    glVertex3f(0.766f, 0.1f, 0.0f);
    glVertex3f(0.716f, 0.1f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.26,0.26, 0.26);
    glVertex3f(0.783f, 0.016f, 0.0f);
    glVertex3f(0.833f, 0.016f, 0.0f);
    glVertex3f(0.833f, 0.1f, 0.0f);
    glVertex3f(0.783f, 0.1f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.26,0.26, 0.26);
    glVertex3f(0.85f, 0.016f, 0.0f);
    glVertex3f(0.9f, 0.016f, 0.0f);
    glVertex3f(0.9f, 0.1f, 0.0f);
    glVertex3f(0.85f, 0.1f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.26,0.26, 0.26);
    glVertex3f(0.916f, 0.016f, 0.0f);
    glVertex3f(0.966f, 0.016f, 0.0f);
    glVertex3f(0.966f, 0.1f, 0.0f);
    glVertex3f(0.916f, 0.1f, 0.0f);
    glEnd();
    glPopMatrix();



    ///BusWheels
    glPushMatrix();
    glTranslatef(_move2+0.7, -0.8, 0.0);
    glScalef(0.8,0.7,0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.06;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_move2+0.7, -0.8, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.03;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move2+0.92, -0.8, 0.0);
    glScalef(0.8,0.7,0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.06;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move2+0.92, -0.8, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.03;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();


}

void point(GLfloat c1,GLfloat c2){
         glPointSize(1.5);
    glBegin(GL_POINTS);

    glColor3ub(255,255,255);
    glVertex2f(c1, c2);
    glEnd();
}

void star1()///MINHAJUL
{
      point(-.93,.83);    ///recursive call
      point(-.85,.77);
      point(-.72,.70);
      point(-.74,.90);
      point(-.67,.86);
      point(-.61,.67);
      point(-.55,.59);
      point(-.51,.66);
      point(-.47,.84);
      point(-.43,.95);
      point(-.39,.75);
      point(-.33,.55);
      point(-.25,.68);
      point(-.20,.81);
      point(-.17,.74);
      point(-.12,.93);
      point(-.08,.67);
      point(-.04,.97);
      point(.06,.73);
      point(.02,.55);
      point(.93,.83);
      point(.85,.77);
      point(.72,.70);
      point(.74,.90);
      point(.67,.86);
      point(.61,.67);
      point(.55,.59);
      point(.51,.66);
      point(.47,.84);
      point(.43,.95);
      point(.39,.75);
      point(.33,.55);
      point(.25,.68);
      point(.20,.81);
      point(.17,.74);
      point(.12,.93);

}

void car() ///MINHAJUL
{
    glPushMatrix();                       ///glbegin er moto kaj kore
    glTranslatef(_move6, -0.9f, 0.0f);   ///x axix e move koracchi so oita move6 variable nisi baki gula fixed rakhsi
    glColor3f(0.0,0.0,1.0);              ///RGB we took BLUE value of B=1
    glBegin(GL_POLYGON);
        glVertex2f(-0.85, 0.0);
        glVertex2f(-0.55, 0.0);
        glVertex2f(-0.55, 0.07);
        glVertex2f(-0.60, 0.07);
        glVertex2f(-0.65, 0.17);
        glVertex2f(-0.75, 0.17);
        glVertex2f(-0.80, 0.17);
        glVertex2f(-0.85, 0.07);
        glVertex2f(-0.85, 0.0);
    glEnd();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);  ///black 000
    glPushMatrix();
    glTranslatef(_move6, -0.9f, 0.0f);
    glBegin(GL_POLYGON);           ///first window
        glVertex2f(-0.61, 0.07);
        glVertex2f(-0.66, 0.16);
        glVertex2f(-0.79, 0.16);
        glVertex2f(-0.84, 0.07);
    glEnd();
    glPopMatrix();

    glColor3f(0.000, 0.545, 0.545);  ///border between two windows
    glPushMatrix();
    glTranslatef(_move6, -0.9f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.73, 0.07);
        glVertex2f(-0.72, 0.07);
        glVertex2f(-0.72, 0.16);
        glVertex2f(-0.73, 0.16);
    glEnd();
    glPopMatrix();

    glPushMatrix();
   glTranslatef(_move6, -0.9f, 0.0f);
        glTranslatef(-0.80,0.01,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);   ///next window of car
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)   ///wheel
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;                ///redious of wheel circle
            float x = r * cos(A);
            float y = r * sin(A);          ///build in func
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move6, -0.9f, 0.0f);
        glTranslatef(-0.80,0.01,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);              ///inner white circle for wheel
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
   glTranslatef(_move6, -0.9f, 0.0f);
        glTranslatef(-0.62,0.01,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);   ///next wheel
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move6, -0.9f, 0.0f);
        glTranslatef(-0.62,0.01,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);  ///next wheel inner white
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();


}

void plane() ///MINHAJUL
{
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0, 1.0);    ///white body plane
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(-0.366f, 0.55f, 0.0f);
    glVertex3f(-0.45f, 0.616f, 0.0f);
    glVertex3f(-0.5f, 0.66f, 0.0f);
    glVertex3f(-1.0f, 0.66f, 0.0f);
    glEnd();

    ///Plane Windows
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0, 0.0);   ///red
    glVertex3f(-0.966f, 0.55f, 0.0f);
    glVertex3f(-0.916f, 0.55f, 0.0f);
    glVertex3f(-0.916f, 0.63f, 0.0f);
    glVertex3f(-0.966f, 0.63f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0, 1.0);
    glVertex3f(-0.866f, 0.55f, 0.0f);
    glVertex3f(-0.816f, 0.55f, 0.0f);
    glVertex3f(-0.816f, 0.63f, 0.0f);
    glVertex3f(-0.866f, 0.63f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0, 1.0);
    glVertex3f(-0.766f, 0.55f, 0.0f);
    glVertex3f(-0.716f, 0.55f, 0.0f);
    glVertex3f(-0.716f, 0.63f, 0.0f);
    glVertex3f(-0.766f, 0.63f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0, 1.0);
    glVertex3f(-0.666f, 0.55f, 0.0f);
    glVertex3f(-0.616f, 0.55f, 0.0f);
    glVertex3f(-0.616f, 0.63f, 0.0f);
    glVertex3f(-0.666f, 0.63f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0, 0.0);
    glVertex3f(-0.566f, 0.55f, 0.0f);
    glVertex3f(-0.516f, 0.55f, 0.0f);
    glVertex3f(-0.516f, 0.63f, 0.0f);
    glVertex3f(-0.566f, 0.63f, 0.0f);
    glEnd();

    ///Plane sides

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0, 0.0);  ///red one
    glVertex3f(-0.916f, 0.66f, 0.0f);
    glVertex3f(-0.83f, 0.66f, 0.0f);
    glVertex3f(-0.883f, 0.833f, 0.0f);
    glVertex3f(-0.916f, 0.833f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0, 1.0);    ///blue one
    glVertex3f(-0.66f, 0.66f, 0.0f);
    glVertex3f(-0.583f, 0.66f, 0.0f);
    glVertex3f(-0.633f, 0.833f, 0.0f);
    glVertex3f(-0.7f, 0.833f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0, 1.0);   ///blue one
    glVertex3f(-0.66f, 0.33f, 0.0f);
    glVertex3f(-0.616f, 0.33f, 0.0f);
    glVertex3f(-0.583f, 0.516f, 0.0f);
    glVertex3f(-0.68f, 0.516f, 0.0f);
    glEnd();
    glPopMatrix();
}

void grassFlower() /// SADIA
{
    glLoadIdentity();   ///replace kore matrix take
	glMatrixMode(GL_MODELVIEW);  ///aksathe show kore duita
	glPushMatrix();
    glScalef(.10,.10,0);
    glTranslatef(4.0f, -4.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex3f(0.60f, 0.30f, 0.0f);
    glVertex3f(0.30f, .30f, 0.0f);
    glVertex3f(0.30f, 0.60f, 0.0f);
    glVertex3f(0.60f, 0.60f, 0.0f);

    glEnd();
    glPopMatrix();


}

void grassFlower2() ///SADIA
{
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    glScalef(.10,.10,0);
    glTranslatef(5.0f, -5.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex3f(0.60f, 0.30f, 0.0f);
    glVertex3f(0.30f, .30f, 0.0f);
    glVertex3f(0.30f, 0.60f, 0.0f);
    glVertex3f(0.60f, 0.60f, 0.0f);

    glEnd();
    glPopMatrix();


}

void grassFlower3() ///SADIA
{
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    glScalef(.10,.10,0);
    glTranslatef(6.0f, -6.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex3f(0.60f, 0.30f, 0.0f);
    glVertex3f(0.30f, .30f, 0.0f);
    glVertex3f(0.30f, 0.60f, 0.0f);
    glVertex3f(0.60f, 0.60f, 0.0f);

    glEnd();
    glPopMatrix();


}
void grassFlower4()  ///SADIA
{
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    glScalef(.10,.10,0);
    glTranslatef(7.0f, -7.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex3f(0.60f, 0.30f, 0.0f);
    glVertex3f(0.30f, .30f, 0.0f);
    glVertex3f(0.30f, 0.60f, 0.0f);
    glVertex3f(0.60f, 0.60f, 0.0f);

    glEnd();
    glPopMatrix();


}

void rgrassFlower()
{
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    glScalef(.15,.10,0);
    glTranslatef(-4.0f, -4.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(0.60f, 0.30f, 0.0f);
    glVertex3f(0.30f, .30f, 0.0f);
    glVertex3f(0.30f, 0.60f, 0.0f);
    glVertex3f(0.60f, 0.60f, 0.0f);

    glEnd();
    glPopMatrix();


}

void rgrassFlower2()
{
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    glScalef(.15,.10,0);
    glTranslatef(-5.0f, -5.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(0.60f, 0.30f, 0.0f);
    glVertex3f(0.30f, .30f, 0.0f);
    glVertex3f(0.30f, 0.60f, 0.0f);
    glVertex3f(0.60f, 0.60f, 0.0f);

    glEnd();
    glPopMatrix();


}

void rgrassFlower3()
{
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    glScalef(.15,.10,0);
    glTranslatef(-6.0f, -6.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(0.60f, 0.30f, 0.0f);
    glVertex3f(0.30f, .30f, 0.0f);
    glVertex3f(0.30f, 0.60f, 0.0f);
    glVertex3f(0.60f, 0.60f, 0.0f);

    glEnd();
    glPopMatrix();


}
void rgrassFlower4()
{
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    glScalef(.15,.10,0);
    glTranslatef(-7.0f, -7.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(0.60f, 0.30f, 0.0f);
    glVertex3f(0.30f, .30f, 0.0f);
    glVertex3f(0.30f, 0.60f, 0.0f);
    glVertex3f(0.60f, 0.60f, 0.0f);

    glEnd();
    glPopMatrix();


}
void lamp() /// SADIA
{
    glLoadIdentity(); ///so that the new viewing parameters are not combined with the previous one.
	glMatrixMode(GL_MODELVIEW); ///can consider one value among the values
	glPushMatrix();
    glTranslatef(.9, -0.5f, 0.0f);
    glScalef(.5,.5,0);  ///produces a general scaling along the x, y, and z axes.

 glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);  ///Orange
    glVertex2f(-0.01f, 0.4f);
    glVertex2f(-0.01f, -0.3f);
    glVertex2f(0.01f, -0.3f);
    glVertex2f(0.01f, 0.4f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f); ///Blue
    glVertex2f(-0.04f, -0.3f);
    glVertex2f(-0.04f, -0.35f);
    glVertex2f(0.04f, -0.35f);
    glVertex2f(0.04f, -0.3f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.1f, 0.1f); ///Dark blue
	glVertex2f(-0.06f, -0.35f);
    glVertex2f(-0.07f, -0.38f);
    glVertex2f(0.07f, -0.38f);
    glVertex2f(0.06f, -0.35f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex2f(-0.04f, 0.4f);
    glVertex2f(0.0f, 0.38f);
    glVertex2f(0.04f, 0.4f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(0.0f, 0.55f);
    glVertex2f(-0.05f,0.5f);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); ///yellow
    glVertex2f(0.0f, 0.55f);
	glVertex2f(0.05f, 0.5f);
	glVertex2f(0.025f, 0.6f);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);///yellow
    glVertex2f(0.0f, 0.55f);
	glVertex2f(-0.05f,0.5f);
	glVertex2f(-0.025f, 0.6f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);///red
	glVertex2f(0.025f, 0.6f);
    glVertex2f(0.0f, 0.55f);
    glVertex2f(-0.025f, 0.6f);
    glVertex2f(0.0f, 0.65f);
	glEnd();
	glPopMatrix();
}

void lamp2() ///SADIA
{
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    glTranslatef(-.9, -0.5f, 0.0f);
    glScalef(.5,.5,0);

 glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);///Orange
    glVertex2f(-0.01f, 0.4f);
    glVertex2f(-0.01f, -0.3f);
    glVertex2f(0.01f, -0.3f);
    glVertex2f(0.01f, 0.4f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f); ///Blue
    glVertex2f(-0.04f, -0.3f);
    glVertex2f(-0.04f, -0.35f);
    glVertex2f(0.04f, -0.35f);
    glVertex2f(0.04f, -0.3f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.1f, 0.1f); ///Dark blue
	glVertex2f(-0.06f, -0.35f);
    glVertex2f(-0.07f, -0.38f);
    glVertex2f(0.07f, -0.38f);
    glVertex2f(0.06f, -0.35f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex2f(-0.04f, 0.4f);
    glVertex2f(0.0f, 0.38f);
    glVertex2f(0.04f, 0.4f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(0.0f, 0.55f);
    glVertex2f(-0.05f,0.5f);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); ///yellow
    glVertex2f(0.0f, 0.55f);
	glVertex2f(0.05f, 0.5f);
	glVertex2f(0.025f, 0.6f);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); ///yellow
    glVertex2f(0.0f, 0.55f);
	glVertex2f(-0.05f,0.5f);
	glVertex2f(-0.025f, 0.6f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f); ///red
	glVertex2f(0.025f, 0.6f);
    glVertex2f(0.0f, 0.55f);
    glVertex2f(-0.025f, 0.6f);
    glVertex2f(0.0f, 0.65f);
	glEnd();
	glPopMatrix();
}


void night(){  ///SUMYA


    nightSky();
    moon();

    glLoadIdentity();
    glPushMatrix();
    stairs();
    field();
    glScalef(.7,.7,0);
    glTranslatef(0.0f, -0.05f, 0.0f);
    memorial();
    borderPool();
    pool();

    lamp();
    lamp2();


    flag();
    road();
    moon();
    star1();
    manyStar(0,.4);
    tree();
    tree2();
    bus();
    car();
    grassFlower();
    grassFlower2();
    grassFlower3();
    rgrassFlower();
    rgrassFlower2();
    rgrassFlower3();

    rain();
    glPopMatrix();
    glFlush();
}

void day()  ///SADIA
{
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();



    sky();    ///recursive call korse
    cloud();
    glTranslatef(-1.3, -0.1, 0.0);
    cloud2();
    glPopMatrix();
    bird();
    stairs();
    field();
    glScalef(.7,.7,0);
    glTranslatef(0.0f, -0.05f, 0.0f);
    memorial();
    borderPool();
    pool();
    lamp();
    lamp2();
    flag();
    road();
    sun();
    rain();
    tree();
    tree2();
    bus();
    car();
    plane();
    grassFlower();
    grassFlower2();
    grassFlower3();
    rgrassFlower();
    rgrassFlower2();
    rgrassFlower3();
    glPopMatrix();
    glFlush();
}
void national_memorialN() {
night();
}
void national_memorialD() {
day();
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{	speed += 0.01f;
			}
if (button == GLUT_RIGHT_BUTTON)
	{speed -= 0.01f;   }
glutPostRedisplay();

}

void handleKeypress(unsigned char key, int x, int y) { ///MINHAJUL
	switch (key) {
	    case  'd':  ///day
	        glutDestroyWindow(1);
	        glutInitWindowSize(1200, 720);
            glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-720)/2);
            glutCreateWindow("National Martyrs Memorial (Day View)");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(national_memorialD);
            break;


         case 'n':  ///night
            glutDestroyWindow(1);
	        glutInitWindowSize(1200, 720);
            glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-720)/2);
            glutCreateWindow("National Martyrs Memorial (Night View)");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(national_memorialN);
            glutPostRedisplay();
            break;

        case 's':   ///Stop
            speed = 0.0f;
            break;
        case 'a':   ///speed bare
            speed = 0.1f;
            break;

        case 'r':   ///Rain
            temp=1;
            break;
        case 't':   ///Rain stop
            temp=0;
            break;
        case 'o':  ///BUS start
            stop=1;
            break;
        case 'p':  ///BUS stop
            stop=0;
            break;

            }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 720);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("National Martyrs Memorial");
    init();                      ///putting the system into graphics mode
    glutDisplayFunc(national_memorialN);
    glutDisplayFunc(national_memorialD);
    glutTimerFunc(10, update, 0);
    glutTimerFunc(10, update2, 0); ///for moving purpose
    glutMouseFunc(handleMouse);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}
