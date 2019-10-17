#ifndef MODELO_JER_HPP
#define MODELO_JER_HPP


#include "matrices-tr.h"
#include "objeto3d.h"
#include "grafo-escena.h"
#include "malla-revol.h"


class C : public NodoGrafoEscena
{

private:

  // Param 0
  Matriz4f* mat_rotacion;

  // Param 1
  Matriz4f* mat_escalado_pelota1;
  Matriz4f* mat_traslacion_pelota1;

  // Param 2
  Matriz4f* mat_escalado_pelota2;
  Matriz4f* mat_traslacion_pelota2;

  // Param 3
  Matriz4f* mat_rotacion_helice1;

  // Param 4
  Matriz4f* mat_rotacion_helice2;

  // Param 5
  Matriz4f* mat_traslacion_helice1;

  // Param 6
  Matriz4f* mat_traslacion_helice2;
  
 public:

  C();

  void actualizarEstadoParametro(const unsigned iParam, const float t_sec);

  unsigned leerNumParametros() const;
  
};


/* Esfera que se agranda y achica entre radio 1 y 2 */

class PelotaInflable : public NodoGrafoEscena
{  

};


class Helice : public NodoGrafoEscena
{
  
};


class CilindroCerrado : public MallaRevol {
  
public:

  CilindroCerrado(const int num_verts_per,
	   const unsigned nperfiles);
};


class Brazo : public NodoGrafoEscena
{

};


class Eje : public NodoGrafoEscena{

public:

  Eje();
};


class Soporte: public NodoGrafoEscena{

public:

  Soporte();
};


#endif // MODELO_JER_HPP
  
