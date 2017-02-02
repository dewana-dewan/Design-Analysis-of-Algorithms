#include <iostream>
#define LL long long
#define FOR(i, n, m) for(i = m; i < n; i++)

using namespace std;

void swap(LL int *a, LL int *b) {
	LL int temp;
	temp  = *b;
	*b = *a;
	*a = temp;
}

int main() {
	int tst, n, i, j;
	LL int temp, nega;
	cin >> tst;
	while(tst--) {
		cin >> n;
		LL int arr[n];
		nega = 0;
		FOR(i, n, 0) {
			cin >> arr[i] >> temp;
			nega += temp;
			arr[i] += temp;
		}
		FOR(i, 2, 0) {
			FOR(j, n - 1, 0)
				if(arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
		}
		cout << arr[n - 1] + arr[n -2] - nega << endl;
	}
	return 0;
}
