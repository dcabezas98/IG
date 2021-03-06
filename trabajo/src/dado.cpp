#include <math.h>
#include "ig-aux.h"
#include "materiales-luces.h"
#include "dado.h"

using namespace std;

Dado::Dado() : MallaInd("Dado"){

  vertices={
	    {0,1,1}, // A 0
	    {0,0,1}, // B 1
	    {1,1,1}, // C 2
	    {1,0,1}, // D 3
	    {0,1,0}, // E 4
	    {0,1,0}, // E 5
	    {0,0,0}, // F 6
	    {0,0,0}, // F 7
	    {1,1,0}, // G 8
	    {1,1,0}, // G 9
	    {1,1,0}, // G 10
	    {1,0,0}, // H 11 
	    {1,0,0}, // H 12
	    {1,0,0}  // H 13
  };

  triangulos={
	      {0,1,2}, // Cara 1
	      {1,3,2},
	      {3,1,6}, // Cara 2
	      {6,11,3},
	      {0,4,7}, // Cara 3
	      {0,7,1},
	      {2,3,12}, // Cara 4
	      {2,12,8},
	      {0,2,5}, // Cara 5
	      {5,2,9},
	      {4,10,7}, // Cara 6
	      {10,13,7}
  };

  cc_tt_ver={
	     {0.5, 1.0/3.0},  //A
	     {0.5, 2.0/3.0},  //B
	     {0.75, 1.0/3.0}, //C
	     {0.75, 2.0/3.0}, //D
	     {0.25, 1.0/3.0}, //E
	     {0.5, 0},        //E 
	     {0.5, 1},        //F
	     {0.25, 2.0/3.0}, //F
	     {1, 1.0/3.0},    //G
	     {0.75, 0},       //G
	     {0, 1.0/3.0},    //G
	     {0.75, 1},       //H
	     {1, 2.0/3.0},    //H
	     {0, 2.0/3.0},    //H
  };

  calcularNormales();
}

NodoDado::NodoDado(){

  Textura *text = new Textura("imgs/dice.jpg");
  Material *mat = new Material(text, 0.5, 0.5, 0.5, 4);

  agregar(mat);
  agregar(new Dado());
}

Dado24::Dado24() : MallaInd("Dado24")
{

    vertices =
      {  { -1.0, -1.0, -1.0 }, // 0
         { -1.0, -1.0, +1.0 }, // 1
         { -1.0, +1.0, -1.0 }, // 2
         { -1.0, +1.0, +1.0 }, // 3
         { +1.0, -1.0, -1.0 }, // 4
         { +1.0, -1.0, +1.0 }, // 5
         { +1.0, +1.0, -1.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7

	 { -1.0, -1.0, -1.0 }, // 0 +8
         { -1.0, -1.0, +1.0 }, // 1 +8
         { -1.0, +1.0, -1.0 }, // 2 +8
         { -1.0, +1.0, +1.0 }, // 3 +8
         { +1.0, -1.0, -1.0 }, // 4 +8
         { +1.0, -1.0, +1.0 }, // 5 +8
         { +1.0, +1.0, -1.0 }, // 6 +8
         { +1.0, +1.0, +1.0 }, // 7 +8

	 { -1.0, -1.0, -1.0 }, // 0 +16
         { -1.0, -1.0, +1.0 }, // 1 +16
         { -1.0, +1.0, -1.0 }, // 2 +16 
         { -1.0, +1.0, +1.0 }, // 3 +16
         { +1.0, -1.0, -1.0 }, // 4 +16
         { +1.0, -1.0, +1.0 }, // 5 +16
         { +1.0, +1.0, -1.0 }, // 6 +16
         { +1.0, +1.0, +1.0 } // 7 +16
      } ;


   triangulos =
      {  {0,1,3}, {0,3,2}, // X-
         {4,7,5}, {4,6,7}, // X+
         {8,13,9}, {8,12,13}, // Y-
         {10,11,15}, {10,15,14}, // Y+
         {16,22,20}, {16,18,22}, // Z-
         {17,21,23}, {17,23,19}  // Z+
      } ;

   cc_tt_ver=
     {{0.25,2.0/3.0}, // 0
      {0.5,2.0/3.0}, // 1
      {0.25,1.0/3.0}, // 2
      {0.5,1.0/3.0}, // 3
      {1,2.0/3.0}, // 4
      {0.75,2.0/3.0}, // 5
      {1,1.0/3.0}, // 6
      {0.75,1.0/3.0}, // 7

      {0.5,1}, // 0 +8
      {0.5,2.0/3.0}, // 1 +8
      {0.5,0}, // 2 +8
      {0.5,1.0/3.0}, // 3 +8
      {0.75,1}, // 4 +8
      {0.75,2.0/3.0}, // 5 +8
      {0.75,0}, // 6 +8
      {0.75,1.0/3.0}, // 7 +8

      {0.25,2.0/3.0}, // 0 +16
      {0.5,2.0/3.0}, // 1 +16
      {0.25,1.0/3.0}, // 2 +16 
      {0.5,1.0/3.0}, // 3 +16
      {0,2.0/3.0}, // 4 +16
      {0.75,2.0/3.0}, // 5 +16
      {0,1.0/3.0}, // 6 +16
      {0.75,1.0/3.0} // 7 +16
     };
   
   calcularNormales();
}


NodoDado24::NodoDado24(){

  Textura *text = new Textura("imgs/dice.jpg");
  Material *mat = new Material(text, 0.5, 0.5, 0.5, 4);

  agregar(mat);
  agregar(new Dado24());
}
