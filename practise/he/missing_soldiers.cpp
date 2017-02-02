#include <iostream>
#include <set>
#define FOR(i, l, m) for(i = m; i <= l; i++)

using namespace std;

int main() {
	set <long long int> a;
	set <long long int>::iterator it;
	long long int x, y, d, i;
	int tst;
	cin >> tst;
	while(tst--) {
		cin >> x >> y >> d;
		FOR(i, d + x, x){
			a.insert(i);
		}
	}
	/*
	for(it = a.begin(); it != a.end(); ++it) {
		cout << *it << endl;
	}
	*/
	cout << a.size() << endl;
	return 0;
}
