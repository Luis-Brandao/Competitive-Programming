#include <iostream>
#include <set>
using namespace std;
set<int> stalls;

bool fits(int k, int c) {
	int start = *stalls.begin();
	int count = 1;

	for(int x : stalls) {
		if(x - start >= k) {
			start = x;
			count++;
		}
	}

	return count >= c;
}

int search(int low, int high, int c) {
	int count, start;
	int mid  = low + ((high - low) / 2);

	if(!fits(low, c)) return low - 1;

	//cout << "ola" << endl;

	if(fits(mid, c)) {
		return search(mid+1, high, c);
 
	}else {
		return search(low, mid, c);
	}
}

int main() {
	int n, t, x;
	cin >> t;
	int c;
	while(t--) {
		cin >> n;
		cin >> c;

		while(n--) {
			cin >> x;
			stalls.insert(x);

		}
		int high = *(--stalls.end());
	    int low  = 0;

	
	    cout << search(low, high, c) << endl;

	    stalls.clear();
	}

}