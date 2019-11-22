// Grupo VJ25,SERGIO ALBERTO LUIS CANO, MARCOS DOCAMPO PRIETO-PUGA
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>

class colaVip
{
public:
	colaVip(int p);						// constructora
	~colaVip();							// destructora
	void push(int p, const T&elem);		// introducir elemento con prioridad
	T const& front() const;				// devolver el primer elemento
	void pop();							// eliminar el primer elemeto
	bool empty() const;					// preguntar si es vacia
	size_t size() const;				// preguntar tamaño de la cola
private:
	const int p;						// clases
	int largo = 0;						// nombre
	vector<queue<T>> filaDeColas;		//vector de colas
};

template<typename T>
colaVip<T>::colaVip(int p): p(p)
{
	for (int a = 0; a < p; a++) {
		filaDeColas.push_back(queue<T>());
	}
}

template<typename T>
colaVip<T>::~colaVip()
{
}

template<typename T>
void colaVip<T>::push(int p, const T & elem)
{
	filaDeColas[p].push(elem);
	largo++;
}

template<typename T>
T const & colaVip<T>::front() const
{	
	int i = 0;
	while (i < filaDeColas.size() && filaDeColas[i].empty()) {
		i++;
	}
	return filaDeColas[i].front();
}

template<typename T>
void colaVip<T>::pop()
{
	int i = 0;
	while (i < filaDeColas.size() && filaDeColas[i].empty()) {
		i++;
	}
    filaDeColas[i].pop();
	largo--;
}

template<typename T>
bool colaVip<T>::empty() const
{
	return largo == 0;
}

template<typename T>
size_t colaVip<T>::size() const
{
	return largo;
}

//Aqui comienza el programa
void resolver(int clases,int aperturas,int aforo) {
	char orden;
	int prioridad, nombre, genteDentro = 0, largoCola = 0;
	colaVip<int> V (clases);
	for (int r = 0; r < aperturas; r++) {	//mete gente en la disco o en la cola
		cin >> orden;
		switch (orden)
		{
		case '+':
			{
				cin >> prioridad;
				cin >> nombre;
				if (genteDentro < aforo) {		//si cabe gente en la disco lo mete
					genteDentro++;
				}
				else {							//si no cabe va a la cola
					V.push(prioridad, nombre);
					largoCola++;
				}
			}
			break;
		case '-': 
			{
				genteDentro--;
				if (largoCola > 0) {			//si sale alguien saco al mayor VIP de la cola y lo meto en la disco
					genteDentro++;
					largoCola--;
					V.pop();
				}
			}
			break;
		default:
			break;
		}
	}
	if (V.empty()) {
		cout << "NADIE" << "\n";
	}
	else {
		while (!V.empty()) {
			cout<< V.front() <<" ";
			V.pop();
			genteDentro--;
		}
		cout << "\n";
	}
	
}
void resuelveCaso() {
	//[leer los datos de la entrada]
	int clases,aperturas,aforo;
	std::cin >> clases;
	std::cin >> aperturas;
	std::cin >> aforo;
	resolver(clases,aperturas,aforo);
}
int main() {
	int daysOpen;
	std::cin >> daysOpen;
	for (int i = 0; i < daysOpen; ++i) {
		resuelveCaso();
	}
	system("pause");
	return 0;
}