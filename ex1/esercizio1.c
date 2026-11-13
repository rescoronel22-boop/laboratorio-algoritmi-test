#include<stdio.h>

//funzioni prototipo
void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);
void hybrid_sort(int array[], int low, int high, int k);

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

void hybrid_sort(int array[], int low, int high, int k){
    if (low < high) {
        int size = high - low + 1;

        // Se la dimensione è minore o uguale a k selection sort
        if (size <= k) {
            selection_sort(array + low, size);
        } 
        else {
            // Altrimenti quicksort ricorsivo
            int pi = partition(array, low, high);

            // Chiamate ricorsive sulle due metà
            hybrid_sort(array, low, pi - 1, k);
            hybrid_sort(array, pi + 1, high, k);
        }
    }
}

int main(){
	int n = 10;
	int array[] = {23, 1, 4, 3, 24, 12, 45, 56, 67, 59};
	int k = 4;
	//printf("Selection sorting:\n");
	//printf("quicksort:\n");
	printf("hybrid_sort:\n");
	
	printf("Unsorted list: ");
	for(int i = 0; i <= n-1; i++){
		printf("%d ", array[i]);
	}
	hybrid_sort(array, 0, n - 1, k);
	printf("\n\nSorted list: ");
	for(int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
	return 0;
}