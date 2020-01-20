#ifndef IG_DADO_HPP
#define IG_DADO_HPP

#include <vector>          // usar std::vector
#include <string>

#include "objeto3d.h"   // declaración de 'Objeto3D'
#include "malla-ind.h"
#include "grafo-escena.h"

class Dado : public MallaInd
{

public:
  Dado();
};


class NodoDado : public NodoGrafoEscena
{

 public:
  NodoDado();
};


class Dado24 : public MallaInd
{
 public:
  Dado24();
};


class NodoDado24 : public NodoGrafoEscena
{
 public:
  NodoDado24();
};

#endif
