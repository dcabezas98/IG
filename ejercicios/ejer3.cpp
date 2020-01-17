
void dibujarPoligono(int n){

  std::vector<Tupla3f> vertices ;
  
  for(int i = 0; i < n; i++){
    float alpha = i*2.0*M_PI/n;

    vertices.push_back({0.75*cos(alpha), 0.75*sin(alpha),0});
  }

  glDisable(GL_DEPTH_TEST);

  // Relleno
  glColor3f(0,1,1);


  // DIFERIDO VAO
  
  // Relleno
  GLuint id_vao;
  glGenVertexArrays(1, &id_vao); // crea 1 VAO
  glBindVertexArray(id_vao); // activar VAO

  // Crear VBO
  unsigned long tam = sizeof(Tupla3f)*(unsigned long) vertices.size();
  
  GLuint id_vbo;
  glGenBuffers(1, &id_vbo); // crea 1 VBO
  glBindBuffer(GL_ARRAY_BUFFER, id_vbo); // activar VBO
  glBufferData(GL_ARRAY_BUFFER, tam, vertices.data(), GL_STATIC_DRAW); // RAM->GPU
  
  // Registrar tabla
  glVertexPointer(3,GL_FLOAT,0,0);
  glEnableClientState(GL_VERTEX_ARRAY); // Habilitar uso de la tabla, cuando es un GL_ARRAY_BUFFER

  // Dibujar
  glDrawArrays(GL_POLYGON, 0, vertices.size());
  
  // Contorno
  glLineWidth(4);
  glColor3f(0,0.2,0.8);

  // Dibujar
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawArrays(GL_POLYGON, 0, vertices.size());

  glBindBuffer(GL_ARRAY_BUFFER, 0); // No dejar activado el VBO

  
  // INMEDIATO BEGIN_END
  /*
  glBegin(GL_POLYGON);

  for(int i = 0; i < n; i++)
    glVertex3fv(vertices[i]);

  glEnd();

  // Contorno
  glLineWidth(4);
  
  glColor3f(0,0.2,0.8);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);

  for(int i = 0; i < n; i++)
    glVertex3fv(vertices[i]);

  glEnd();
  */
  
  
  // INMEDIATO DRAWARRAYS
  /*
  // Registrar tabla
  glBindBuffer(GL_ARRAY_BUFFER, 0); // Activar VBO (id==0 si está en RAM)

  glVertexPointer(3,GL_FLOAT,0,vertices.data());

  glEnableClientState(GL_VERTEX_ARRAY);
  
  // Dibujar
  glDrawArrays(GL_POLYGON, 0, vertices.size());

  // Contorno
  glLineWidth(4);
  glColor3f(0,0.2,0.8);

  // Dibujar
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawArrays(GL_POLYGON, 0, vertices.size());
  */

  
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glLineWidth(1);

  glEnable(GL_DEPTH_TEST);

  glBindVertexArray(0);
}

void DibujadorPoligono::visualizarGL(ContextoVis & cv){
  dibujarPoligono(n);
}
