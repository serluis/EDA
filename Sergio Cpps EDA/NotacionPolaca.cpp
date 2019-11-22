// GRUPO VJ25
// SERGIO ALBERTO LUIS CANO
// MARCOS DOCAMPO PRIETO-PUGA

// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema
#include <vector>
#include <stack>
#include <iostream>
//#include <cstdlib>
using namespace std;

// funci�n que resuelve el problema
// comentario sobre el coste, O(f(n)) donde 'n' es...
// *Es necesario calcular el coste de todas las funciones llamadas desde resolver()*


		/*for(int i = 0; i < NumOperandos; i++){
			cin >> paso;
			cola.push(paso);
		}		
		while(!cola.empty()){
			paso = cola.top();
		}*/
int resolver(int NumOperandos) {
	stack <int> cola;
	int sol = 0, alfa, beta, charlie;
	char paso;
	
	while (NumOperandos > 0) {
		cin >> paso;
			switch (paso) {
			case '-':				
				alfa = cola.top();
				cola.pop();
				beta = cola.top();
				cola.pop();
				charlie = beta - alfa;
				cola.push(charlie);
				break;
			case '+':
				alfa = cola.top();
				cola.pop();
				beta = cola.top();
				cola.pop();
				charlie = beta + alfa;
				cola.push(charlie);
				break;
			default:				
				charlie = (paso - '0');
				cola.push(charlie);
				break;
			}
		NumOperandos--;
	}
	return cola.top();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
void cogeDatos() {
	int NumOperandos;
	cin >> NumOperandos;
	if (NumOperandos > 0) {
		int resultado = resolver(NumOperandos);
		cout << resultado << "\n";
	}
	else { cout << "\n"; }
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		cogeDatos();
	}
	system("pause");
	return 0;
}
//3
//1 5
//3 53 -
//5 53 - 2 +
//5 489+-
//7 648+-5-