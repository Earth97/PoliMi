#include <stdio.h>
#define N 10
void printSign(char *, int, int);

int main() {
	int n;
	char *arr;
	do
		scanf("%d", &n);
	while (n < 0 || n > N);
	if (arr = (char*)malloc(n*sizeof(char)))
		printSign(arr, n, 0);
	else
		printf("Errore di memoria!\n");
	return 0;
}

void printSign(char arr[], int n, int index) {
	if (index == n) {
		for (index = 0; index < n; index++)
			printf("%c", arr[index]);
		printf("\n");
		return;
	}
	arr[index] = '+';
	printSign(arr, n, index+1);
	arr[index] = '-';
	for (index = 0; index < n; index++)
		printf("%c", arr[index]);
	printf("\n");
	
}
			