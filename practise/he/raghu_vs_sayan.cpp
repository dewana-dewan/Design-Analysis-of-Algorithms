#include <iostream>
#define LL long long

using namespace std;

LL int min(LL int a, LL int b) {
	if(a > b)
		return b;
	else
		return a;
}
void swap(LL int *a, LL int *b) {
	LL int tmp;
	tmp = *a;
	*a = *b; 
	*b = tmp;
}
LL int right(LL int a) {
	return 2*(a+1);
}
LL int left(LL int a) {
	return 2*(a+1) - 1;
}

void min_heapify(LL int *arr,LL int i, LL int siz) {
	LL int temp, l, r, lar;
	l = left(i);
	r = right(i);
	if(l < siz && arr[i] > arr[l]) {
		temp = l;
	}
	else
		temp = i;
	if(r < siz && arr[temp] > arr[r])
		temp = r;
	if (temp != i) { 
		lar = arr[temp];
		arr[temp] = arr[i];
		arr[i] = lar;
		min_heapify(arr, temp, siz);
	}
}

int main()
{
	int tst;
	cin >> tst;
	LL int a, b, temp, i, j;
	while(tst--) {
		cin >> a >> b >> temp;
		LL int arr[temp];
		for(i = 0; i < temp; i++ ) {
			cin >> arr[i];
		}
		for(i = temp; i >= 0; i--) {
			min_heapify(arr, i, temp);
			//for(j = 0; j< temp; j++) 
			//    cout << arr[j] << "  ";
			//cout << endl;

		}
		/*
		   for(i = 0; i< temp; i++) 
		   cout << arr[i] << "  ";
		   cout << endl;
		 */
		int k = 0;
		for(i = 0; i < temp;) {
			//cout << arr[i] << " ";
			if(((a-arr[i]) < 0 && (b-arr[i]) < 0) ||(a - arr[i]) == 0 && (b - arr[i]) == 0 ) {
				cout << "Tie";
				k++;
				break;
			}
			if((a-arr[i]) < 0 && (b - arr[i]) >= 0) {
				cout << "Sayan Won";
				k++;
				break;    
			}
			if((b-arr[i]) < 0 && (a - arr[i]) >= 0 ) {
				k++;
				cout << "Raghu Won";
				break;
			}
			b -= arr[i];
			a -= arr[i];
			arr[i] = arr[temp - 1];
			temp--;
			min_heapify(arr, i, temp);
		}
		if(k == 0)
			cout << "Tie";
		cout << endl;

	}
	return 0;
}



/*
   void insert(LL int arr[], LL int val, int *siz) {
   (*siz)++;
   arr[siz] = INT_MIN;
   incres(arr, siz, val);
   }

   void incres(LL int arr[], int val, int i) {
   if(arr[i] > val)
   return;
   arr[i] = val;
   while( i >= 1 && arr[par(i)] > arr[i]) {
   swap(&(arr[par(i)]), &(arr[i]));
   i = par(i);
   }
   }
 */


