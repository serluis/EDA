// Grupo VJ05, Nuria Bango Iglesias y Marcos Llinares Montes

// elemento_situado detecta si el vector ordenado y sin repeticiones
// contiene algun elemento bien situado
#include <iostream>
#include <vector>

// función que resuelve el problema
// O(f(log n)), donde n es v.size()
bool elemento_situado(const std::vector<int>& v, int ini, int fin)
{
	const int n = fin - ini;
	if (n == 0)
		return false;
	else if (n == 1)
		return (v[ini] == ini);
	else
	{
		const int mit = (ini + fin) / 2;
		
		if (!elemento_situado(v, ini, mit))
			return elemento_situado(v, mit, fin);
		else
			return true;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada y escribiendo la respuesta
void resuelveCaso() {
	int n;
	std::cin >> n;
	std::vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int j;
		std::cin >> j;
		v.push_back(j);
	}
	if (elemento_situado(v, 0, v.size()))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}