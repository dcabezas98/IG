// *********************************************************************
// **
// ** Informática Gráfica, curso 2019-20
// ** Implementación de la clase 'MallaRevol'
// **
// *********************************************************************

#include "ig-aux.h"
#include "tuplasg.h"
#include "lector-ply.h"
#include "matrices-tr.h"
#include "malla-revol.h"
#include <math.h>

using namespace std ;

// *****************************************************************************




// Método que crea las tablas de vértices, triángulos, normales y cc.de.tt.
// a partir de un perfil y el número de copias que queremos de dicho perfil.
void MallaRevol::inicializar
(
   const std::vector<Tupla3f> & perfil,     // tabla de vértices del perfil original
   const unsigned               num_copias  // número de copias del perfil
)
{
   // COMPLETAR: Práctica 2: completar: creación de la malla....

  int m = perfil.size();


  // Inicializar tabla de vértices
  for(int i = 0; i < num_copias; i++)
    for(int j = 0; j < m; j++)
      {
	float alpha = 2*M_PI*i/(num_copias-1);
	float c = cos(alpha);
	float s = sin(alpha);
	vertices.push_back({perfil[j][X]*c-perfil[j][Z]*s, perfil[j][Y], perfil[j][X]*s+perfil[j][Z]*c});
      }

  // Inicializar tabla de triángulos
  for(int i = 0; i < num_copias-1; i++)
    for(int j = 0; j < m-1; j++)
      {
	int k = i*m+j;
	triangulos.push_back({k, k+m, k+m+1});
	triangulos.push_back({k, k+m+1, k+1});
      }
}


// -----------------------------------------------------------------------------
// constructor, a partir de un archivo PLY

MallaRevolPLY::MallaRevolPLY
(
   const std::string & nombre_arch,
   const unsigned      nperfiles
)
{
   ponerNombre( std::string("malla por revolución del perfil en '"+ nombre_arch + "'" ));
   // COMPLETAR: práctica 2: crear la malla de revolución
   // Leer los vértice del perfil desde un PLY, después llamar a 'inicializar'
   // ...........................

   std::vector<Tupla3f> perfil;
   
   LeerVerticesPLY(nombre_arch, perfil);

   inicializar(perfil, nperfiles);   
}


Cilindro::Cilindro(const int num_verts_per,
	   const unsigned nperfiles)
{
  ponerNombre("Cilindro");
    
  std::vector<Tupla3f> perfil;
  for(int i = 0; i < num_verts_per; i++)
    perfil.push_back({1,(float)i/(num_verts_per-1),0});

  inicializar(perfil, nperfiles);
}


Cono::Cono(const int num_verts_per,
	   const unsigned nperfiles)
{
  ponerNombre("Cono");
  
  std::vector<Tupla3f> perfil;

  for(int i = 0; i < num_verts_per; i++)
    perfil.push_back({1-(float)i/(num_verts_per-1),(float)i/(num_verts_per-1),0});

  inicializar(perfil, nperfiles);
}


Esfera::Esfera(const int num_verts_per,
	       const unsigned nperfiles)
{
  ponerNombre("Esfera");

  std::vector<Tupla3f> perfil;

  for(int i = 0; i < num_verts_per; i++){
    float alpha = M_PI*((float)i/(num_verts_per-1)-(float)1/2);
    perfil.push_back({cos(alpha),sin(alpha),0});
  }
  
  inicializar(perfil, nperfiles);
}