#include <iostream>
#include <climits>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
	int tst, siz, i ,j, k, max, min;
	map<int, int> mp;
	scanf("%d", &tst);
	while(tst--) {
		//scanf("%d", &siz);
		cin >> siz;
		max = INT_MIN;
		min = INT_MAX;
		int max_i, min_i;
		while(siz--) {
			cin >> k;
			if(!mp.count(k))
				mp[k] = 0;
			mp[k]++;
			//cout << k << " " << mp[k] << endl;
			if(max < mp[k]) {
				max = mp[k];
				max_i = k;

			}
			if(min >= mp[k]) {
				min = mp[k];
				min_i = k;

			}
		}
		//cout << max << "\t" << min << endl;
		//cout << max_i << "\t" << min_i << endl;
		if(max - min <= 0 || min_i == max_i)
			cout << -1 << endl;
		else
			cout << max - min << endl;
		mp.clear();
	}
	return 0;
}
