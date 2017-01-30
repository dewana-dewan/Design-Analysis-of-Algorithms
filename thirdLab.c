# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);

int main()
{
	char **input;
	char ch=' ';
	int n,k,i,j;
	srand(time(NULL));
	scanf("%d",&n);
	scanf("%d",&k);
	input = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		input[i]=(char *)malloc((k+1)*sizeof(char));
		for(j=0;j<k;j++)
			input[i][j]=(rand()%95)+32;
		input[i][k]='\0';
	}
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}
	radix_sort(input,n,k);
	printf("*******\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}

	return 0;
}

void count_sort(char **input, int n, int k, int i) {
	//printf("i is %d\n", i);
	int count[100];
	char output[n][k + 1];
	int j, l;

	for(j = 0; j < 100; j++)
		count[j] = 0;
	for(j = 0; j < n; j++) { 
		printf("%d\n", count[input[j][i] - 32]++);	
	}
	for(j = 1; j < 100; j++) {
		count[j] += count[j - 1];
		//printf("%d --> %d\n",j, count[j]);
	}

	for(j = n-1 ; j >= 0; j--) {
		strncpy(output[count[input[j][i] - 32] - 1], input[j], k + 1 );
		count[input[j][i]-32]--;

	}
	for(j = n-1 ; j >= 0; j--) 
		strncpy(input[j], output[j], k + 1);
}

void count_sort1(char **input, int n , int k, int id)
{

	int count[100];
	int i;
	for(i = 0; i < 100; i++) {
		count[i] = 0;	
	}
	for(i = 0; i < n; i++) {
		//printf("%d ", input[i][id] - 32); 
		count[input[i][id] - 32]++;
	}
	printf("\n");
	for(i = 1; i < 100; i++) {
		count[i] += count[i-1];	
		//printf("%d ", count[i]);	
	}
	//printf("\n");
	char temp1[k+1];
	for(i = n-1; i >= 0;) {
		int temp = count[input[i][id] - 32] - 1;
		if(temp == i) {
			count[input[i][id] - 32]--;
			i--;
		} else {
			strcpy(temp1, input[temp]);
			strcpy(input[temp], input[i]);
			strcpy(input[i], temp1);
		}
	}

}

void radix_sort(char **input,int n,int k)
{
	/* The function sorts the array input using radix sort
	   Write the two versions of the radix sort here, one after another.
	   To execute one of the version just comment out the other version.
	 */

	// V1

	printf("in radix");
	int i;
	for( i = k - 1; i >= 0; i--) { 
		//count_sort(input, n, k, i);
		count_sort1(input, n, k, i);
	}
}
