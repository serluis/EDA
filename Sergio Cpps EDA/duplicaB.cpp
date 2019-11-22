// Grupo VJ25,SERGIO ALBERTO LUIS CANO, MARCOS DOCAMPO PRIETO-PUGA
// Comentario general sobre la solución:
// recogeremos los datos por el programa y los 
// iremos multiplicando por 2 en una funcion aparte que lo devolvera
#include <iostream>

// FUNCIONES AUXILIARES

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int solucion(int num) {
	return num * 2;
}
// Resuelve un caso de prueba, leyendo de la entrada y escribiendo la respuesta
void resuelveCaso() {
	int num;
	std::cin >> num;
	while (num != 0) {
		int sol;
		sol = solucion(num);
		std::cout << sol << "\n";
		std::cin >> num;
	}
}
int main() {
	resuelveCaso();
	return 0;
}