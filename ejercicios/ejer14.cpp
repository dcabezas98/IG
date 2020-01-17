
using namespace std;

int n; // Vértices
vector<Tupla3i> tri; // Tengo
vector<Tupla2i> ari; // Quiero rellenar

// Caso 1: Triángulos con orientación no coherente
void generaAri(){

  vector<vector<int>> pares(n-1); // Matriz de n*k

  int menor, mayor;

  for(int i = 0; i < tri.size(); i++){ // 2n
    for(int j = 0; j < 3; j++){
      menor = min(tri[i][j], tri[i][(j+1)%3]);
      mayor = max(tri[i][j], tri[i][(j+1)%3]);

      if(find(pares[menor].begin(),pares[menor].end(),mayor)==pares[menor].end()){ // La arista no estaba añadida
	ari.push_back({menor, mayor});
	pares[menor].push_back(mayor);
      }
    }
  }
}


// Caso 2: Triángulos con orientación coherente

void generaAri(){

  int a, b;
  
  for(int i = 0; i < tri.size(); i++){
    for(int j = 0; j < 3; j++){
      a = tri[i][j];
      b = tri[i][(j+1)%3];

      if(a < b)
	ari.push_back({a,b});
    }
  }
}
