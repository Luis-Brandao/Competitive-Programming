#include <iostream>
#include <set>
#include <cmath>

#define MAX_TRIES 100

using namespace std;
int p,q,r,s,t,u;

double f(double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u;
}

double fDerivative(double x) {
	return -p * exp(-x) + q * cos(x) - r * sin(x) + s / (cos(x) * cos(x)) + 2 * t * x;
}

double search() {
	double x = 0.5; //Primeira tentativa de descobrir a raiz da função
	double x1;      //Próxima tentativa
	double error;
	int tries = 0;
	cout << "ola";


	//Iteramos este algoritmo até obtermos uma resposta com a precisão pedida
	while(error > 0.0001 || tries < MAX_TRIES) {
		tries++;
		x1    = x - f(x)/fDerivative(x);
		error = abs(f(x1 - x));
	}
	return x1 - x;
}

int main() {
	cin >> p >> q >> r >> s >> t >> u;
		cout << search() << endl;
	//}
}