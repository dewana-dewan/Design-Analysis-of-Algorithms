# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
int qksort(int *,int ,int ,int);
int part(int *,int,int);
void swap(int *,int *);
void bsort(int* ,int ,int);

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

int qksort(int *arr,int l,int h,int k){
//	printf("hahhaha%d",h);
	if(h<=l) return 0;
	if(h-l<=k){
		bsort(arr,l,h);
		return 0;
	}
	int p=part(arr,l,h);
	qksort(arr,l,p-1,k);
	qksort(arr,p,h,k);
	return 0;
}

int part(int * arr, int l ,int h){
	
	int x=arr[l+(h-l)/2];
	while(l<h){
		while(arr[l]<x) l++;
		while(x<arr[h]) h--;
		if(l<h){
			swap(&arr[l],&arr[h]);
		++l;
		--h;
		}}
	return l;
}



void hybridSort(int *arr, int n)
{

  //write your program here.....
   //  use the following block of code to find out the time of running a particular routine
     clock_t begin,end;
	int k=1;
	for(k=1;k<=100;k++){
	int i;

//RANDOM INPUTS
	for(i=0;i<n;++i){
		arr[i]=rand()%100;
		}

	



     begin = clock();
     
     qksort(arr,0,n-1,k);

     end = clock();

  //   time required will be end-begin


 //     For random input use the following code

  //    arr[i] = rand();

  //for(i=0;i<n;++i) printf(" %d  \n",arr[i]);
   //printf("\n\n");
     //output should be printed in the following way for each k.

     printf("%d,%d\n",k,(int)end-begin);

 }
     

}

