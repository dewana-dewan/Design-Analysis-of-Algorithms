#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	
	int siz, i, ans, j;
	cin >> siz;
	string arr[siz];
	for(i = 0; i < siz; i++) {
		cin >> arr[i];
		
//		getline(cin ,arr[i]);
	}
	for( i = 0; i < siz; i++) {
//		cout << endl << arr[i] << endl;
		ans = 0;
		for (j = 0; j < i; j++) {
//			cout << arr[j];
			if(arr[i].compare(arr[j]) > 0)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
