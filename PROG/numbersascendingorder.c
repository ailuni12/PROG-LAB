#include <stdio.h>

#define SIZE 10

void findMinMax(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    
    for (int i = 1; i < size; ++i) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int arr[SIZE] = {9, 2, 7, 4, 5, 1, 10, 3, 8, 6};
    int min, max;
    
    // Find minimum and maximum values
    findMinMax(arr, SIZE, &min, &max);
    
    // Print in ascending order
    printf("Array in ascending order from minimum to maximum:\n");
    printf("%d", min);
    for (int i = min + 1; i <= max; ++i) {
        printf(", %d", i);
    }
    printf("\n");
    
    return 0;
}