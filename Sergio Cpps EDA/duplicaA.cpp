// Grupo VJ25,SERGIO ALBERTO LUIS CANO, MARCOS DOCAMPO PRIETO-PUGA
// Comentario general sobre la solución:
// recogeremos los datos por el programa y los 
// iremos multiplicando por 2 en una funcion aparte que lo devolvera
#include <iostream>

// FUNCIONES AUXILIARES

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(int datos) {
	return datos * 2;
}
// Resuelve un caso de prueba, leyendo de la entrada y escribiendo la respuesta
void resuelveCaso() {
	//[leer los datos de la entrada]
	int num;
	std::cin >> num;
	int sol = resolver(num);
	
	//[escribir sol]
	std::cout << sol << "\n";
}
int main() {
	int numCasos,sol;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	return 0;
}