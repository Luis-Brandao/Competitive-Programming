#include <iostream>
#include <unordered_map>
using namespace std;
// Complexidade temporal = O(n)
// Complexidade espcial  = O(n)
int main(){
	int t,n,snowflake,openEnding,maxSoFar, start, count;
	
	unordered_map<int,int> lastPos;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		lastPos.clear();
		maxSoFar = 0;
	    start = 0;
	    count = 0;

		for(int i = 0 ; i < n ; i++) {
			scanf("%d", &snowflake);
			openEnding = true;

            //O c++ não tem contains() ???
            //Não uso o operador "[]" para evitar confusões com o número zero
			if(lastPos.find(snowflake) != lastPos.end()) {

				int pos = lastPos[snowflake];
				//O snoflake já existiu numa sequência passada.
				//Isto significa que a maior sequência admissível até agora seria (POS)...(i)
				
				
				if(pos >= start){
					//Se o índice START estiver atrás da última posição vista, temos de
				    //tornar a posição imediatamente a seguir no novo começo, de maneira a que não existam
				    //duplicados neste segmento. 

					start = pos + 1;
				}


				//Repetindo este teste para todos os items de cada segmento iterativamente, temos garantias de nunca
				//existem elementos duplicados num segmento, e que simultâneamente estamos a obter o
				//maior segmento possível.

				//O tamanho resultante do segmento até este snoflake i - start. Na próxima linha adicionamos
				//o elemento atual a esta contagem.
				count = i - start;
			}
			count++;

			//Atualizamos o registo da última posição deste snoflake.
			lastPos[snowflake] = i;

			maxSoFar = max(maxSoFar, count);
		}

		printf("%d\n", maxSoFar);
	}
}