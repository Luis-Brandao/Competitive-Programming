#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;    //mapa com o custo base de cada item
int S;            //orçamento
int n;            //número de objectos no mercado

int totalCost;

vector<int> cost(int k) {
	vector<int> costVector;

	for(int i = 0 ; i < n ; i++) {
		costVector.push_back(v[i] + i*k);
	}
	return costVector;
}

int howMany(int k) {
    //Ordenamos os custos ascendentemente
    vector<int> costVector = cost(k);

    sort(costVector.begin(), costVector.end());

    int i;

	//Conseguimos comprar i+1 objectos sem ultrapassar o orçamento
	for(i = 0 ; i < n ; i++) {
		if(totalCost + costVector[i] > S) return totalCost; else break;
	}

	return i;
}
int maxN;
int search(int low, int high) {
	int mid = low + (high - low)/2;

    if(howMany(low) < maxN) return low - 1;

    int numberOfObjects = howMany(mid); 
	if(numberOfObjects > maxN) {
		maxN = numberOfObjects;
		search(mid, high);

	}else search(low, mid);
	return 0;
}

int main() {
    cin >> n >> S;
    int x;
	while(n--) {
		cin >> x;
		v.push_back(x);
	}
	maxN = -1;
	int result = search(0, n);
	vector<int> totalCost = cost(result);

	cout <<  result << totalCost[result];
}