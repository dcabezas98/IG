void Diamante::visualizarGL(ContextoVis & cv){

  glColor3f(0,1,1);
  
  glBindBuffer(GL_ARRAY_BUFFER, 0); // Activar VBO (id==0 si está en RAM)
  glVertexPointer(3,GL_FLOAT,0,vertices.data());
  glEnableClientState(GL_VERTEX_ARRAY);

  glDrawElements(GL_TRIANGLES, 3*triangulos.size(), GL_UNSIGNED_INT, triangulos.data());

  glColor3f(0,0.2,0.8);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawElements(GL_TRIANGLES, 3*triangulos.size(), GL_UNSIGNED_INT, triangulos.data());

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  
  glBindVertexArray(0);
}

// En main.cpp:
// para dibujar los polígonos rellenos más atrás que las aristas
  glEnable( GL_POLYGON_OFFSET_FILL );
  glPolygonOffset( 1.0, 1.0 );
