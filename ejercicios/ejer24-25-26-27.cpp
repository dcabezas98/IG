
void gancho(){

  glBegin(GL_LINE_STRIP);

  glVertex3f(0,0,0);
  glVertex3f(1,0,0);
  glVertex3f(1,1,0);
  glVertex3f(0,1,0);
  glVertex3f(0,2,0);

  glEnd();
  glFlush();
}

void gancho_x4(){

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  for(int i = 0; i < 4; i++){
    gancho();
    glTranslatef(0,2,0);
    glRotatef(90.0,0,0,1);
  }
}

void gancho_2p_a(float x0, float y0, float x1, float y1){

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  float phi = atan2(x1-x0, y1-y0);

  float mod = sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
  float esc = mod/2.0;
  
  glTranslatef(x0,y0,0);
  glRotatef(-phi*180.0/M_PI, 0,0,1);
  glScalef(esc,esc,esc);
  gancho();
}

void gancho_2p_b(float x0, float y0, float x1, float y1){

  float ux, uy, vx, vy;

  vx = (x1-x0)/2;
  vy = (y1-y0)/2;
  
  ux=vy;
  uy=-vx;

  glBegin(GL_LINE_STRIP);
  glColor3f(1,0,0);
  glVertex3f(x0,y0,0);
  glVertex3f(x0+ux,y0+uy,0);
  glVertex3f(x0+ux+vx,y0+uy+vy,0);
  glVertex3f(x0+vx,y0+vy,0);
  glVertex3f(x0+2*vx,y0+2*vy,0);
  glEnd();
  glFlush();
}

void engranaje(int n){

  float alpha,beta;

  glColor3f(0,1,0);
  
  for(int i = 0; i < n; i++){
    
    alpha = (float)(i-0.5)*2.0*M_PI/n;
    beta = (float)(i+0.5)*2.0*M_PI/n;
      
    gancho_2p_b(cos(alpha),sin(alpha),cos(beta),sin(beta));
  }
}
