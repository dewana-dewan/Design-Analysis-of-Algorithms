# include <stdio.h>
# include <stdlib.h>

int check_MAX_heap(int *,int,int);
void build_MAX_heap(int *,int, int);
int extract_MAX(int *,int, int);
void insert(int *,int,int,int);
void change(int *,int,int,int,int);
void max_heapify(int arr[],int i,int k, int n);
int child(int i, int j, int k);
int parent(int i, int k);

int main()
{
	char ch=' ';
	int *arr,n,k,i,new;
	scanf("%d",&k);
	scanf("%d",&n); /* To have anything non-trivial, n should be >2*n*k*/
	arr = (int *)malloc(2*n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	if(!check_MAX_heap(arr,n,k)) {
		build_MAX_heap(arr,n,k);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	do
	{
		while(getchar()!='\n'); /* To clear the buffer of any leftover characters*/
		ch=getchar();
		switch(ch)
		{
			case 'i':
				scanf("%d",&new);
				insert(arr,n,k,new);
				n++;
				break;
			case 'd':
				printf("%d",extract_MAX(arr,n,k));
				n--;
				break;
			case 'c':
				scanf("%d",&i);
				scanf("%d",&new);
				change(arr,n,k,i,new);
				break;
		}

		for(i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
		}
	}while(ch!='q');
	return 0;
}

int check_MAX_heap(int arr[],int n,int k)
{
	/* The function returns 0 if arr is NOT a k-ary MAX-heap.*/
	int i, j;
	int cnt;
	for (i = 1; i < n / k; i++) { 
		for(j = 1; j <= k; j++) {
			if(arr[i] < arr[k * i + j])
				return 0;
		}
	}
	return 1;
}

void build_MAX_heap(int arr[],int n,int k) {
	/* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
	int i, j;
	for(i = n - n / k; i >= 0; i--) {
		max_heapify(arr, i, k, n);	
	}
}

void max_heapify(int arr[],int i,int k, int n) {
	int j;
	while(i < n) {
		int cnt = 1, largest = i, temp;
		for(j = 1; j <= k; j++) {
			if(child(i, j, k) < n && arr[child(i, j, k)] > arr[largest]) 
				largest = child(i, j, k);
		}
		if(largest == i)
			return;
		temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		i = largest;
	}
}

void insert(int arr[],int n,int k,int new)
{
	/* This function inserts a new element into the k-ary MAX-heap arr*/
	int i, j, prnt;
	arr[n] = new;
	i = n;
	while(i >= 0 && arr[parent(i, k)] < arr[i]) {
		prnt = parent(i, k);
		j = arr[i];
		arr[i] = arr[prnt];
		arr[prnt] = j;
		i = prnt;
	}
}

int extract_MAX(int arr[],int n,int k)
{
	/* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
	int max = arr[0];
	arr[0] = arr[n - 1];
	max_heapify(arr, 0, k, n);
	return max;
}

void change(int arr[],int n,int k,int i,int new)
{
	/* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
	int old, j, l;
	old = arr[i];
	arr[i] = new;
	if(new > old) {
		while(i >= 0 && arr[parent(i ,k)] < arr[i]){
			l = arr[i];
			arr[i] = arr[parent(i, k)];
			arr[parent(i, k)] = l;
			i = parent(i, k);
		}
	}
	else {
		while (i < n) {
			int  largest = i, temp;
			for(j = 1; j <= k; j++) {
				if(child(i, j, k) < n && arr[child(i, j, k)] > arr[largest]) 
					largest = child(i, j, k);
			}
			if(i == largest) 
				return;
			l = arr[i];
			arr[i] = arr[largest];
			arr[largest] = l;
			i = largest;
		}
	}
}

int child(int i, int j, int k) {
	return i * k + j;
}

int parent(int i, int k) {
	return (i - 1) / k;
}
