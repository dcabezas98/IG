
#include <math.h>
#include "ig-aux.h"
#include "matrices-tr.h"
#include "grafo-escena.h"
#include "modelo-jer.h"
#include "malla-revol.h"

using namespace std;

// C

C::C(){
  ponerNombre("C");
  
  agregar(new PelotaInflable());
}

unsigned C::leerNumParametros() const{
    
  int numParam = 0;

  for(int i=0; i < entradas.size(); i++)
    if(entradas[i].tipo==TipoEntNGE::objeto)
      numParam+=entradas[i].objeto->leerNumParametros();

  return numParam;
}


void C::actualizarEstadoParametro(const unsigned iParam, const float t_sec){
  
}


// PelotaInflable

PelotaInflable::PelotaInflable(){

  ponerNombre("Pelota inflable");

  int i = agregar(MAT_Traslacion(1.5+6.0,0.0,0.0));
  mat_traslacion = leerPtrMatriz(i);
  
  i = agregar(MAT_Escalado(1.5, 1.5, 1.5)); // Matriz escalado
  mat_escala = leerPtrMatriz(i);
  
  i=agregar(new Esfera(50,50));
  entradas[i].objeto->ponerColor({1.0,0.0,0.0}); // Hacer la esfera roja
}


unsigned PelotaInflable::leerNumParametros() const{
  return 1;
}


void PelotaInflable::actualizarEstadoParametro(const unsigned iParam, const float t_sec){

  assert(iParam<leerNumParametros());
  
  switch(iParam){
  case 0:
    float v=1.5+6.0+0.5*sin(M_PI*t_sec*0.5);
    *mat_traslacion = MAT_Traslacion(v,0.0,0.0);
    *mat_escala = MAT_Escalado(v-6.0,v-6.0,v-6.0);
    break;
  }
}


// Helice

Helice::Helice(){

  ponerNombre("Helice");

  int i = agregar(MAT_Rotacion(0.0, 1.0, 0.0, 0.0));
  mat_rotacion = leerPtrMatriz(i);

  agregar(MAT_Escalado(0.2,3.0,0.4));
  agregar(MAT_Rotacion(45.0,0.0,1.0,0.0)); // Rotar 45º respecto eje Y
  i = agregar(new CilindroCerrado(10,5)); // Saldrá un prisma cuadrangular
  entradas[i].objeto->ponerColor({0.8,0.8,0.2});
}


unsigned Helice::leerNumParametros() const{
  return 1;
}


void Helice::actualizarEstadoParametro(const unsigned iParam, const float t_sec){

  cout << "AQUI NO LLEGA " << endl;

  assert(iParam<leerNumParametros());
  
  switch(iParam){
  case 0:
    *mat_rotacion = MAT_Rotacion(t_sec*180.0, 1.0, 0.0, 0.0);
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

  agregar(MAT_Rotacion(90.0,0.0,0.0,1.0));
  agregar(MAT_Escalado(0.2,12.0,0.2));
  
  int i = agregar(new CilindroCerrado(20,50));
  entradas[i].objeto->ponerColor({0.0,0.0,1.0});
}

// Brazo

Brazo::Brazo(){

  ponerNombre("Brazo");

  agregar(new Eje()); 
  agregar(new PelotaInflable());

  int i = agregar(MAT_Traslacion(0.0,0.0,0.0));
  mat_trasl_helice = leerPtrMatriz(i);
  
  agregar(new Helice());
}


unsigned Brazo::leerNumParametros() const{
    
  int numParam = 1;

  for(int i=0; i < entradas.size(); i++)
    if(entradas[i].tipo==TipoEntNGE::objeto)
      numParam+=entradas[i].objeto->leerNumParametros();

  return numParam;
}


void Brazo::actualizarEstadoParametro(const unsigned iParam, const float t_sec){

  assert(iParam<leerNumParametros());

  cout << "I: " << iParam << endl;
  
  switch(iParam){

  case 0: // Rotacion de la helice
    cout << "HOla 0" << endl;
    entradas[0].objeto->actualizarEstadoParametro(0, t_sec);
    cout << "adios 0 " << endl;
    break;

  case 1:{ // Traslacion de la helice
    cout << "HOla 1" << endl;
    float v = 5.9*sin(M_PI*0.25*t_sec); 
    *mat_trasl_helice = MAT_Traslacion(v, 0.0, 0.0);
    cout << "adios 1 " << endl;
    break;
  }
    
  case 2: // Agrandamiento de la pelota
    cout << "HOla 2" << endl;
    entradas[2].objeto->actualizarEstadoParametro(0, t_sec);
    cout << "adios 2 " << endl;    
    break;
  }
}
