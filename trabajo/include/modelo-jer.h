#ifndef MODELO_JER_HPP
#define MODELO_JER_HPP


#include "matrices-tr.h"
#include "objeto3d.h"
#include "grafo-escena.h"
#include "malla-revol.h"


class C : public NodoGrafoEscena
{
 public:

  C();

  void actualizarEstadoParametro(const unsigned iParam, const float t_sec);

  unsigned leerNumParametros() const;
  
};


/* Esfera que se agranda y achica entre radio 1 y 2 */

class PelotaInflable : public NodoGrafoEscena
{
private:

  Matriz4f* mat_escala;
  Matriz4f* mat_traslacion;
  
public:

  PelotaInflable();

  void actualizarEstadoParametro(const unsigned iParam, const float t_sec);

  unsigned leerNumParametros() const;
  
};


class Helice : public NodoGrafoEscena
{
private:

  Matriz4f* mat_rotacion;

public:

  Helice();

  void actualizarEstadoParametro(const unsigned iParam, const float t_sec);

  unsigned leerNumParametros() const;  
};


class CilindroCerrado : public MallaRevol {
  
public:

  CilindroCerrado(const int num_verts_per,
	   const unsigned nperfiles);
};


class Brazo : public NodoGrafoEscena
{
private:

  Matriz4f* mat_trasl_helice;

  public:

  Brazo();

  void actualizarEstadoParametro(const unsigned iParam, const float t_sec);

  unsigned leerNumParametros() const;
  
};


class Eje : public NodoGrafoEscena{

public:
  
  Eje();
};


#endif // MOODELO_JER_HPP
  
