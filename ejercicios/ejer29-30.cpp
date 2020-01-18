
void Tubo()
{
  glPushMatrix();
  glScalef(1,3,1);
  glTranslatef(0,-0.5,0);
  Cilindro();
  glPopMatrix();
}

void Extremidad(float alpha)
{
  glPushMatrix();
  // Ejer 30
  glTranslate(0,1.5,0);
  glRotate(alpha,1,0,0);
  glTranslate(0,-1.5,0);
  //
  Tubo();
  glTranslatef(0,1.5,0);
  Semiesfera();
  glTranslatef(0,-3,0);
  glRotate(180,0,0,1);
  Semiesfera();
  glPopMatrix();
}

void Cuerpo()
{
  glPushMatrix();
  glScalef(5,10,5);
  Cilindro();
  glPopMatrix();
}

void Cabeza(float phi)
{
  glPushMatrix();
  glRotate(phi,0,1,0); // Ejer 30
  glTranslatef(0,10.2,0);
  glScalef(5,5,5);
  Semiesfera();
  glPopMatrix();
}

void Android(float alpha, float beta, float phi)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPushMatrix();
  Cabeza(phi);
  Cuerpo();
  glTranslatef(-2,0,0);
  Extremidad(0);
  glTranslatef(4,0,0);
  Extremidad(0);
  glTranslatef(0,8.5,0);
  glTranslatef(4.2,0,0);
  Extremidad(alpha); // Brazo izquierdo
  glTranslatef(-12.4,0,0);
  Extremidad(beta); // Brazo derecho
  glPopMatrix();
}
