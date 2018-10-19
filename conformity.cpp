#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n = 1, id;
    set<int> s;
    map<set<int>,int> table;
    
	int maxCount;
	int totalCount;

	while(n){
		scanf("%d", &n);
		if(n == 0) return 0;
		while(n--) {
			for(int i = 0 ; i < 5 ; i++) {
				scanf("%d", &id);
				s.insert(id);
			}
			table[s]++;
			s.clear();
		}	
		maxCount = -1;

		for(auto i : table) {
			if(i.second > maxCount){
				maxCount = i.second;
			}
		}
		totalCount = 0;
		for(auto i : table) {
			if(i.second == maxCount){
				totalCount+=i.second;
			}

		}

		table.clear();
		printf("%d\n", totalCount);
	}
	return 0;
}