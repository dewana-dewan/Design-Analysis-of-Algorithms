#include <iostream>
using namespace std;

int main()
{
	long long int arr[3], mid, temp;
	int i, j;
	cin >> arr[0] >> arr[1] >> arr[2];
	for(i = 0; i < 3; i++)
		for(j = 0; j < 2 ; j++) {
			if(arr[j] > arr[ j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	if((arr[2] - arr[1] % 2 == 0))
		cout << arr[1] + (arr[2] - arr[1])/2;
	else
		cout << arr[1] + (arr[2] - arr[1])/2 + 1;

	return 0;
}

