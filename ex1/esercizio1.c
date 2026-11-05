#include<stdio.h>

//implementazione iniziale selection sort
void selection_sort(int array[], int length){
	int min, temp;
	for(int i = 0; i <= length - 1; i++){
		min = i;
		for(int j = i + 1; j <= length - 1; j++){
			if(array[j] < array[min]){
				min = j;
			}
			//swap
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		}
	}
}

int main(){
	int n = 10;
	int array[] = {23, 1, 4, 3, 24, 12, 45, 56, 67, 59};
	printf("Selection sorting:\n");
	
	printf("Unsorted list: ");
	for(int i = 0; i <= n-1; i++){
		printf("%d ", array[i]);
	}
	selection_sort(array, n);
	printf("\n\nSorted list: ");
	for(int i = 0; i < n-1; i++){
		printf("%d ", array[i]);
	}
	return 0;
}