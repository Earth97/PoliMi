/*MERGESORT*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define START 1
void mergeSort(int[], int, int);
void merge(int[], int, int, int);

int main()
{
	int arr[SIZE], i;
	time_t t;
	srand((unsigned)time(&t));
	for (i = 0; i < SIZE; i++)
		arr[i] = rand()%1000;
	mergeSort(arr, START-1, SIZE-1);
	
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}
	

void mergeSort(int a[], int left, int right) {
	int center;
	if (left < right) {
		center = (right+left) / 2;
		mergeSort(a, left, center);
		mergeSort(a, center+1, right);
		merge(a, left, center, right);
	}
	return;
}

void merge(int a[], int left, int center, int right) {
	int *b, i, j, k;
	i = left;
	j = center+1;
	k = 0;
	if (b = (int*)malloc((right-left+1)*sizeof(int))) {
		while (i <= center && j <= right) {
			if (a[i] < a[j]) {
				b[k] = a[i];
				i++;
			} else {
				b[k] = a[j];
				j++;
			}
			k++;
		}
		while (i <= center) {
			b[k] = a[i];
			i++;
			k++;
		}
		while (j <= right) {
			b[k] = a[j];
			j++;
			k++;
		}
		k--;
		while (k >= 0) {
			a[k+left] = b[k];
			k--;
		}
		free(b);
	}
	else 
		printf("Errore di memoria\n");
	return;
}