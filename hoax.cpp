#include <iostream>
#include <set>

using namespace std;
typedef multiset<int>::iterator it;
//Complexidade temporal: O(nlog(n))
//Complexidade espacial: O(n)

int main() {
	//Usamos um set para inserir os valores das compras. Desta maneira podemos aceder ao
	//valor máximo e minimo em tempo constante.

	//Uma vez que as faturas são mantidas na caixa entres diferentes dias,
	//precisamos de usar um multiset para cobrir os casos onde existem duas faturas com o mesmo valor. 
	multiset<int> bills;

    int days, bill, saleN;
    long cost;

    scanf("%d", &days);
    while(days) {

        bills.clear();
        cost = 0;

        while(days--) {
            scanf("%d", &saleN);
            

            while(saleN--) {
            	scanf("%d", &bill);
            	bills.insert(bill);
            }
        
            //O c++ usa ordem descendente para os sets, por isso o último valor vai ser o maior, e o maior será o primeiro. 

            //O iterador .end() corresponde ao fim do cojunto, e não a nenhum objecto do conjunto. 
            //Por isso, temos de decrementar este iterador
            it high = --bills.end();
            it low  = bills.begin();
    
    
            cost += *high - *low;
    
            bills.erase(high);
            bills.erase(low);
        }
        printf("%ld\n", cost);

        //Ler o próximo caso
        scanf("%d", &days);
    }

    return 0;	
}