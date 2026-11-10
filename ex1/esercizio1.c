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

//funzioni prototipo
void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//implementazione iniziale quicksort
void quicksort(int array[], int length){
	quicksort_recursion(array, 0, length - 1);
}

void quicksort_recursion(int array[], int low, int high){
	if(low < high){
		int pivot_index = partition(array, low, high);
		quicksort_recursion(array, low, pivot_index - 1);
		quicksort_recursion(array, pivot_index + 1, high);
	}
}

int partition(int array[], int low, int high) {
    int x = array[low];//pivot
    int p = low;//indice per tracciare la partizione
	int r = high;
    
    //da p+1 fino ad r
    for(int k = p + 1; k <= r; k++){
        if(array[k] <= x){
            p++;
            //swap
            int temp = array[p];
            array[p] = array[k];
            array[k] = temp;
        }
    }
    // Posiziona il pivot al suo posto definitivo
    int temp = array[p];
	array[low] = array[p];
    array[p] = temp;
    
    return p;
}

int main(){
	int n = 10;
	int array[] = {23, 1, 4, 3, 24, 12, 45, 56, 67, 59};
	//printf("Selection sorting:\n");
	printf("quicksort:\n");
	
	printf("Unsorted list: ");
	for(int i = 0; i <= n-1; i++){
		printf("%d ", array[i]);
	}
	quicksort(array, n);
	printf("\n\nSorted list: ");
	for(int i = 0; i < n-1; i++){
		printf("%d ", array[i]);
	}
	return 0;
}