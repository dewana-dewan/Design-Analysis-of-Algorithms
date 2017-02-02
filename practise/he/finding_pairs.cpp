#include <iostream>
#include <map>
using namespace std;

int main()
{
	int tst, i, j, siz, res;
	map <int, int> mp;
	map <int, int>::iterator it;
	cin >> tst;
	while(tst--) {
		cin >> siz;
		res = 0;
		while(siz--) {
			cin >> i;
			mp[i]++;
			//cout << mp[i];
		}
		cout << endl;
		for(it = mp.begin(); it != mp.end(); it++) {
			j = (it -> second)*(it -> second + 1)/2;
			res += j;
		}
		mp.erase(mp.begin(), mp.end());
		cout << res << endl;
	}
	return 0;
}

