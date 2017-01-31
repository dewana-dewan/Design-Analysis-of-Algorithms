#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int tst, siz, len, max, i, j, temp;
	cin >> tst;
	while(tst--) {
		cin >> siz;
		long long int arr[siz];
		cin >> len;
		for(i = 0; i < siz; i++)
			cin >> arr[i];
		sort(arr, arr + i);
		max = 0;
		for(i = 0; i < siz; i++) {
			temp = 0;
			for(j = i; j < siz; j++ ) {
				if(arr[j] - arr[i] + 1 > len)
					break;
				temp ++;
			}
			if(temp > max)
				max = temp;
		}
		cout << max << endl;
	}
	return 0;
}
