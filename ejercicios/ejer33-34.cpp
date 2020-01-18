
void tronco(){

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
    glTranslate(-0.5,3,0);
    glScalef(0.5,0.5,0.5);
    rec(altura-1);
    glPopMatrix();

    glPushMatrix();
    glTranslate(1.5,2.5,0);
    glRotate(-45, 0,0,1);
    float s = 0.70710678;
    glScalef(s,s,s);
    rec(altura-1);
    glPopMatrix();
  }  
}


void arbol(int altura = 4){

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  rec(altura);
}
