# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
int qksort(int *,int ,int ,int);
int part(int *,int,int);
void swap(int *,int *);
void bsort(int* ,int ,int);
void m_merge(int*, int, int);
void m_split(int*, int, int, int);


void bsort(int *arr,int l,int h)
{
	int i,j;
	for(i=l;i<h;++i){
		for(j=l;j<h;j++){
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);
		}
	}
}

void swap(int *a,int *b){
	int x=*a;
	*a=*b;
	*b=x;
}

int main()
{
	int *arr,n;
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(int));
	hybridSort(arr,n);
	return 0;
}

void m_split(int *arr,int l,int h,int k) {
	int m;
	if(h - l <= k ) { 
		bsort(arr, l, h);
		return;
	}
	else {

		//		printf("splitting from %d to %d\n", h, l);
		m = l + ( h - l ) / 2;
		m_split(arr, l, m, k);
		m_split(arr, m + 1, h, k);
		m_merge(arr, l, h);
	}
}

void m_merge(int *arr,int l,int h) {
	//	printf("merging from %d, %d\n", h, l);
	int arr_b[h];
	int m, i, j, k ;
	m = l + (h - l) / 2;
	k = l;
	i = l;
	j = m + 1;
	while(k <= h) {
		if(arr[i] <= arr[j] && i <= m) {
			arr_b[k] = arr[i];
			i++;
		}
		else if (arr[i] > arr[j] && j <= h){
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


void hybridSort(int *arr, int n)
{

	//write your program here.....
	//  use the following block of code to find out the time of running a particular routine
	clock_t begin,end;
	int k=10;
	int i;

	for(k = 1; k <= 100; k++) {
		for(i=0;i<n;++i){
			arr[i]=rand()%100;
		}
		//printf("ok, random values filled\n");

		m_split(arr,0,n - 1,k);

		for(i=0;i<n/2;++i){
			swap(&arr[i],&arr[n-i-1]);
		}

		begin = clock();

		m_split(arr,0,n-1,k);

		end = clock();


		//for(i=0;i<n;++i){
		//	printf("%d\n", arr[i]);
		//}

		printf("%d,%d\n",k,(int)end-begin);
	}


}

