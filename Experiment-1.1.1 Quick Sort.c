#include <stdio.h>

void quickSort(int arr[], int low, int high) {
    
    if (low < high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        int temp;

        while (i < j) {
            while (i <= high && arr[i] <= pivot)
                i++;
            while (arr[j] > pivot)
                j--;

            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
	}
    
    
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
  
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    
    printArray(arr, n);

    return 0;
}
