#include <stdio.h>

int main()
{
	char *arr;
	int i;
	arr = (char*)malloc(sizeof(char) * 100);
	scanf("%s", arr);
	if(arr[0] == '?')
		if(arr[1] == 'b')
			arr[0] = 'a';
	for(i = 1; i < 52; i++){
		printf("%d", i);
		if(arr[i] == '\0')
			break;
		if(arr[i] == '?')
			if(arr[i - 1] == 'b' && (arr[i + 1] == 'b' || arr[i + 1] == '\0'))
				arr[i] = 'a';
			else
				arr[i] = 'b';
	}
	printf("%s", arr);

	return 0;
}

