#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

void poligono(){

  int N = 9;

  glBegin(GL_POINTS);
  glColor3f(0,0,0);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(1.0,0.0,0.0);
  glVertex3f(0.0,1.0,0.0);
  glVertex3f(-1,0,0);
  glVertex3f(0,-1,0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(0, 0.8,1);
  for(unsigned i=0; i<N; ++i)
    glVertex3f(0.75*cos(i*2.0*M_PI/N),0.75*sin(i*2.0*M_PI/N),0.0);
	
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0,0.0,0.8);
  for(unsigned i=0; i<N; ++i)		
    glVertex3f(0.75*cos(i*2.0*M_PI/N),0.75*sin(i*2.0*M_PI/N),0.0);
	
  glEnd();

  glFlush();
}


void tronco(){

  // static int llamadas = 1;
  // cout << "Llamada: " << llamadas << endl;
  // llamadas++;

  glDisable(GL_DEPTH_TEST);
  
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(0.2,0.8,1);
  glBegin(GL_POLYGON);
  glVertex3f(0,0,0);
  glVertex3f(1,0,0);
  glVertex3f(1,1,0);
  glVertex3f(0.5,1.5,0);
  glVertex3f(0,1.5,0);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(1,1,0);
  glVertex3f(2,2,0);
  glVertex3f(1.5,2.5,0);
  glVertex3f(0.5,1.5,0);
  glEnd();
  
  glBegin(GL_POLYGON);
  glVertex3f(0,3,0);
  glVertex3f(-0.5,3,0);
  glVertex3f(0,1.5,0);
  glVertex3f(0.5,1.5,0);   
  glEnd();

  glColor3f(0,0,0.8);
  
  glBegin(GL_LINE_STRIP);
  glVertex3f(1,0,0);
  glVertex3f(1,1,0);
  glVertex3f(2,2,0);
  glEnd();

  glBegin(GL_LINE_STRIP);
  glVertex3f(1.5,2.5,0);
  glVertex3f(0.5,1.5,0);
  glVertex3f(0,3,0);
  glEnd();

  glBegin(GL_LINE_STRIP);
  glVertex3f(-0.5,3,0);
  glVertex3f(0,1.5,0);
  glVertex3f(0,0,0);
  glEnd();

  glFlush();
}



void rec(int altura){

  if(altura == 0)
    tronco();

  else{
    tronco();
    
    glPushMatrix();
    glTranslatef(-0.5,3,0);
    glScalef(0.5,0.5,0.5);
    rec(altura-1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5,2.5,0);
    glRotatef(-45, 0,0,1);
    float s = 0.70710678;
    glScalef(s,s,s);
    rec(altura-1);
    glPopMatrix();
  }
}


void arbol(){
  int altura = 5;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glScalef(0.15,0.15,0.15);

  rec(altura);
}


void myinit(){
  glClearColor(1.0,1.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(5);
  glLineWidth(3);
}


int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(900,900);
  glutInitWindowPosition(50,50);
  glutCreateWindow("Prueba");
  myinit();
  glutDisplayFunc(arbol);
  glutMainLoop();
}



