
void figura_compleja(){

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPushMatrix();
  
  glScalef(0.5,0.5,0.5);
  figura_simple();
  
  glPushMatrix();
  glTranslate(2,2,0)
  glScalef(1,-1,1);
  glRotatef(45,0,0,1);
  float a = sqrt(2);
  glScalef(a,a,a);
  figura_simple();
  glPopMatrix();

  glPushMatrix();
  glTranslate(3,1,0);
  glScalef(2,-1,1);
  figura_simple();
  glPopMatrix();
  
  glPopMatrix();
}
