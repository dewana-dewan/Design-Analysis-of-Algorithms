#include <stdio.h>

void swap(long long int *,long long int *);
void m_merge(long long int*, int, int, long long int p);
void m_split(long long int*, int, int, long long int k);


void swap(long long int *a, long long int *b){
	int x=*a;
	*a=*b;
	*b=x;
}


void m_split(long long int *arr,int l,int h, long long int k) {
	
	int m;
	if(h - l <= 0 ) { 
		return;
	}
	else {
		m = l + ( h - l ) / 2;
		m_split(arr, l, m, k);
		m_split(arr, m + 1, h, k);
		m_merge(arr, l, h, k);
	}
}

void m_merge(long long int *arr,int l,int h, long long int p) {
	//printf("merging from %d, %d\n", h, l);
	int arr_b[h];
	int m, i, j, k ;
	m = l + (h - l) / 2;
	k = l;
	i = l;
	j = m + 1;
	while(k <= h) {
		if(arr[i] % p <= arr[j] % p && i <= m) {
			arr_b[k] = arr[i];
			i++;
		}
		else if (arr[i] % p > arr[j] % p && j <= h){
			arr_b[k] = arr[j];
			j++;
		}
		else {
			if(i <=m ){
				arr_b[k] = arr[i];
				i++;
			}
			if(j <= h){
				arr_b[k] = arr[j];
				j++;
			}

		}
		k++;
	}
	for(i = l; i <= h; i++) {
		arr[i] = arr_b[i];
		//	printf("\t%d \t%d\n", i, arr[i]);
	}

}


int main() {
	int siz, i;
	scanf("%d", &siz);
	long long int arr[siz], k;
	scanf("%lld", &k);	

	for(i = 0;i < siz; i++) {
		scanf("%lld", &arr[i]);	
	}
	m_split(arr, 0, siz - 1, k);
	for(i = 0;i < siz; i++) {
		printf("%lld ", arr[i]);
	}



	return 0;
}
