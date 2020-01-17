
double area(const MallaInd & malla){

  double a = 0;
  Tupla3f p, q, r, u, v;
  

  for(int i = 0; i < malla.triangulos.size(); i++){

    // Vertices del triángulo
    p = malla.vertices[malla.triangulos[i][0]]; 
    q = malla.vertices[malla.triangulos[i][1]];
    r = malla.vertices[malla.triangulos[i][2]];

    // Dos aristas del triángulo
    u = r-p;
    v = q-p;
    
    a+= sqrt(u.cross(v).lengthSq());
  }

  a/=2.0;

  return a;
}
