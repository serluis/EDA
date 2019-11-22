// // GRUPO VJ25
// Sergio Alberto Luis Cano
// Marcos Docampo Prieto-Puga

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema


#include <iostream>
#include <vector>



void merge(std::vector<int>& v, int ini, int mid, int fin) {  //sirve para juntar los vectores
	int l = mid - ini;
	int r = fin - mid;
	std::vector<int>v1, v2;									//creamos espacio adicional para mitades

	for (int i = 0; i < l; i++) {						//rellena el vector
		v1.push_back( v[ini + i]);						//de principio a mitad sin incluir
	}
	for (int j = 0; j < r; j++) {
		v2.push_back(v[mid + j]);						//de mitad a fin
	}

	int i = 0, j = 0;									//esto son marcadores de v1 y v2 (posiciones)
	for (int k = ini; k < fin; k++) {	//k marcador de v	//este for va rellenando el vector original
		if (j >= r ||									//si cont de v2 >= la mitad del vector actual+1 ||
		   (i < l										//si cont de v1 < la mitad del vector actual &&
		 && v1[i] <= v2[j])) {							//interno de v1 menor interno v2
										//resumen: si no has terminado con ningun vector 
										//comparalos y mete el que toque
			v[k] = v1[i];
			i = i + 1;
		}
		else {
			v[k] = v2[j];
			j = j + 1;
		}
	}

}



void mergesort (std::vector<int> &v,int ini,int fin) {
	if (ini < fin - 1) {
		int mid = (ini + fin) / 2;
		mergesort(v, ini, mid);
		mergesort(v, mid, fin);
		merge(v, ini, mid, fin);
	}
	
}

void resuelveCaso() {

	int largo,a;
	std::vector<int> v;
	std::cin >> largo;
	for (int i = 0; i < largo; ++i) {
		std::cin >> a;
		v.push_back(a);
	}
	
	mergesort (v,0,v.size());

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}



int main()
{
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	

	return 0;										//tiene que devolver siempre 0
}