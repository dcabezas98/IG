
void rec(int altura){

  if(altura == 0)
    figura_simple();

  else{
    figura_simple();
    glTranslate(1,0,0);
    glScalef(0.5,0.5,0.5);
    rec(altura-1);
    glTranslate(0,1,0);
    rec(altura-1);
  }
}

void figura_compleja_rec(int altura = 3){

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  rec(altura);
}
