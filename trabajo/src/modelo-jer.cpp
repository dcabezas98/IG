
#include <math.h>
#include "ig-aux.h"
#include "matrices-tr.h"
#include "grafo-escena.h"
#include "modelo-jer.h"
#include "malla-revol.h"

using namespace std;

// C

C::C(){
  
  ponerNombre("Timbálico");

  Esfera* esfera = new Esfera(30,30); // Para las pelotas inflables
  esfera->ponerColor({1.0,0.0,0.0});

  CilindroCerrado* cilindro = new CilindroCerrado(10,5); // Para las hélices
  cilindro->ponerColor({0.8,0.8,0.2});


  int i = agregar(MAT_Traslacion(0.0,0.0,0.0));
  mat_traslacion = leerPtrMatriz(i);
  
  agregar(new Soporte());

  i = agregar(MAT_Rotacion(0.0,0.0,1.0,0.0));
  mat_rotacion = leerPtrMatriz(i);
  
  Brazo* brazo1 = new Brazo();
  brazo1->agregar(MAT_Traslacion(2,0.0,0.0));
  
  // brazo 1
  
  brazo1->agregar(new Eje());
  
  PelotaInflable* pelota1 = new PelotaInflable();

  // pelota 1

  i = pelota1->agregar(MAT_Traslacion(7.5,0.0,0.0));
  mat_traslacion_pelota1 = pelota1->leerPtrMatriz(i);
  
  i = pelota1->agregar(MAT_Escalado(1.5, 1.5, 1.5));
  mat_escalado_pelota1 = pelota1->leerPtrMatriz(i);
  
  pelota1->agregar(esfera);
  
  // fin pelota 1

  brazo1->agregar(pelota1);
  
  i = brazo1->agregar(MAT_Traslacion(3,0.0,0.0));
  mat_traslacion_helice1 = brazo1->leerPtrMatriz(i);
  
  Helice* helice1 = new Helice();

  // helice 1

  i = helice1->agregar(MAT_Rotacion(0.0, 1.0, 0.0, 0.0));
  mat_rotacion_helice1 = helice1->leerPtrMatriz(i);

  helice1->agregar(MAT_Escalado(0.2,3.0,0.4));
  helice1->agregar(MAT_Rotacion(45.0,0.0,1.0,0.0)); // Rotar 45º respecto eje Y
  helice1->agregar(cilindro);

  // fin helice 1

  brazo1->agregar(helice1);
  
  // fin brazo 1


  Brazo* brazo2 = new Brazo();
  brazo2->agregar(MAT_Traslacion(2,0.0,0.0));
  
  // brazo 2
  
  brazo2->agregar(new Eje());
  
  PelotaInflable* pelota2 = new PelotaInflable();

  // pelota 2

  i = pelota2->agregar(MAT_Traslacion(7.5,0.0,0.0));
  mat_traslacion_pelota2 = pelota2->leerPtrMatriz(i);
  
  i = pelota2->agregar(MAT_Escalado(1.5, 1.5, 1.5));
  mat_escalado_pelota2 = pelota2->leerPtrMatriz(i);
  
  i=pelota2->agregar(esfera);
  
  // fin pelota 2

  brazo2->agregar(pelota2);
  
  i = brazo2->agregar(MAT_Traslacion(3,0.0,0.0));
  mat_traslacion_helice2 = brazo2->leerPtrMatriz(i);
  
  Helice* helice2 = new Helice();

  // helice 2

  i = helice2->agregar(MAT_Rotacion(0.0, 1.0, 0.0, 0.0));
  mat_rotacion_helice2 = helice2->leerPtrMatriz(i);

  helice2->agregar(MAT_Escalado(0.2,3.0,0.4));
  helice2->agregar(MAT_Rotacion(45.0,0.0,1.0,0.0)); // Rotar 45º respecto eje Y
  i = helice2->agregar(cilindro); // Saldrá un prisma cuadrangular

  // fin helice 2

  brazo2->agregar(helice2);
  
  // fin brazo 2


  Brazo* brazo3 = new Brazo();
  brazo3->agregar(MAT_Traslacion(2,0.0,0.0));
  
  // brazo 3

  brazo3->agregar(new Eje());
  
  PelotaInflable* pelota3 = new PelotaInflable();

  // pelota 3

  i = pelota3->agregar(MAT_Traslacion(7.5,0.0,0.0));
  mat_traslacion_pelota3 = pelota3->leerPtrMatriz(i);
  
  i = pelota3->agregar(MAT_Escalado(1.5, 1.5, 1.5));
  mat_escalado_pelota3 = pelota3->leerPtrMatriz(i);
  
  i=pelota3->agregar(esfera);
  
  // fin pelota 3

  brazo3->agregar(pelota3);
  
  i = brazo3->agregar(MAT_Traslacion(3,0.0,0.0));
  mat_traslacion_helice3 = brazo3->leerPtrMatriz(i);
  
  Helice* helice3 = new Helice();

  // helice 3

  i = helice3->agregar(MAT_Rotacion(0.0, 1.0, 0.0, 0.0));
  mat_rotacion_helice3 = helice3->leerPtrMatriz(i);

  helice3->agregar(MAT_Escalado(0.2,3.0,0.4));
  helice3->agregar(MAT_Rotacion(45.0,0.0,1.0,0.0)); // Rotar 45º respecto eje Y
  i = helice3->agregar(cilindro); // Saldrá un prisma cuadrangular

  // fin helice 3

  brazo3->agregar(helice3);
  
  // fin brazo 3


  Brazo* brazo4 = new Brazo();
  brazo4->agregar(MAT_Traslacion(2,0.0,0.0));
  
  // brazo 4

  brazo4->agregar(new Eje());
  
  PelotaInflable* pelota4 = new PelotaInflable();

  // pelota 4

  i = pelota4->agregar(MAT_Traslacion(7.5,0.0,0.0));
  mat_traslacion_pelota4 = pelota4->leerPtrMatriz(i);
  
  i = pelota4->agregar(MAT_Escalado(1.5, 1.5, 1.5));
  mat_escalado_pelota4 = pelota4->leerPtrMatriz(i);
  
  pelota4->agregar(esfera);
  
  // fin pelota 4

  brazo4->agregar(pelota4);
  
  i = brazo4->agregar(MAT_Traslacion(3,0.0,0.0));
  mat_traslacion_helice4 = brazo4->leerPtrMatriz(i);
  
  Helice* helice4 = new Helice();

  // helice 4

  i = helice4->agregar(MAT_Rotacion(0.0, 1.0, 0.0, 0.0));
  mat_rotacion_helice4 = helice4->leerPtrMatriz(i);

  helice4->agregar(MAT_Escalado(0.2,3.0,0.4));
  helice4->agregar(MAT_Rotacion(45.0,0.0,1.0,0.0)); // Rotar 45º respecto eje Y
  helice4->agregar(cilindro);

  // fin helice 4

  brazo4->agregar(helice4);

  // fin brazo 4


  // Agregar los brazos

  agregar(brazo1);
  agregar(MAT_Rotacion(90,0,1,0));
  agregar(brazo2);
  agregar(MAT_Rotacion(90,0,1,0));
  agregar(brazo3);
  agregar(MAT_Rotacion(90,0,1,0));
  agregar(brazo4);
}

unsigned C::leerNumParametros() const{
  
  return 14;
}


void C::actualizarEstadoParametro(const unsigned iParam, const float t_sec){

  assert(iParam<leerNumParametros());

  float v;
  
  switch(iParam){

  case 0:
    v=sin(M_PI*t_sec*0.1);
    *mat_traslacion = MAT_Traslacion(0.0,v,0.0);
    break;
    
  case 1:
    *mat_rotacion = MAT_Rotacion(t_sec*90, 0.0, 1.0, 0.0);
    break;

  case 2:
    v=7.5+0.5*sin(M_PI*t_sec*0.5);
    *mat_traslacion_pelota1 = MAT_Traslacion(v,0.0,0.0);
    *mat_escalado_pelota1 = MAT_Escalado(v-6.0,v-6.0,v-6.0);
    break;

  case 3:
    v=7.5+0.5*sin(M_PI*t_sec*0.5);
    *mat_traslacion_pelota2 = MAT_Traslacion(v,0.0,0.0);
    *mat_escalado_pelota2 = MAT_Escalado(v-6.0,v-6.0,v-6.0);
    break;

  case 4:
    v=7.5+0.5*sin(M_PI*t_sec*0.5);
    *mat_traslacion_pelota3 = MAT_Traslacion(v,0.0,0.0);
    *mat_escalado_pelota3 = MAT_Escalado(v-6.0,v-6.0,v-6.0);
    break;

  case 5:
    v=7.5+0.5*sin(M_PI*t_sec*0.5);
    *mat_traslacion_pelota4 = MAT_Traslacion(v,0.0,0.0);
    *mat_escalado_pelota4 = MAT_Escalado(v-6.0,v-6.0,v-6.0);
    break;

  case 6:
    *mat_rotacion_helice1 = MAT_Rotacion(t_sec*360.0, 1.0, 0.0, 0.0);
    break;

  case 7:
    *mat_rotacion_helice2 = MAT_Rotacion(t_sec*360.0, 1.0, 0.0, 0.0);
    break;

  case 8:
    *mat_rotacion_helice3 = MAT_Rotacion(t_sec*360.0, 1.0, 0.0, 0.0);
    break;

  case 9:
    *mat_rotacion_helice4 = MAT_Rotacion(t_sec*360.0, 1.0, 0.0, 0.0);
    break;

  case 10:
    v = 3+2.9*sin(M_PI*0.25*t_sec); 
    *mat_traslacion_helice1 = MAT_Traslacion(v, 0.0, 0.0);
    break;

  case 11:
    v = 3+2.9*sin(M_PI*0.25*t_sec); 
    *mat_traslacion_helice2 = MAT_Traslacion(v, 0.0, 0.0);
    break;

  case 12:
    v = 3+2.9*sin(M_PI*0.25*t_sec); 
    *mat_traslacion_helice3 = MAT_Traslacion(v, 0.0, 0.0);
    break;

  case 13:
    v = 3+2.9*sin(M_PI*0.25*t_sec); 
    *mat_traslacion_helice4 = MAT_Traslacion(v, 0.0, 0.0);
    break;
  }
}


// CilindroCerrado

CilindroCerrado::CilindroCerrado(const int num_verts_per,
				 const unsigned nperfiles){

   ponerNombre("CilindroCerrado");
    
  std::vector<Tupla3f> perfil;
  
  perfil.push_back({0.0,-0.5,0.0});

  for(int i = 0; i < num_verts_per; i++)
    perfil.push_back({1.0,(float)i/(num_verts_per-1)-0.5,0.0});

  perfil.push_back({0.0,0.5,0.0});
  
  inicializar(perfil, nperfiles);
}


// Eje

Eje::Eje(){

  agregar(MAT_Traslacion(3.0,0.0,0.0));
  agregar(MAT_Rotacion(90.0,0.0,0.0,1.0));
  agregar(MAT_Escalado(0.2,6.0,0.2));
  
  int i = agregar(new CilindroCerrado(20,50));
  entradas[i].objeto->ponerColor({0.0,0.0,1.0});
}


// Soporte

Soporte::Soporte(){

  agregar(MAT_Escalado(2.0,1.0,2.0));
  int i = agregar(new CilindroCerrado(20,50));
  entradas[i].objeto->ponerColor({0.8,0.6,0.4});
}
