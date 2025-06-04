#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    int n, i, arr[1000];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    clock_t start,end;
    double time_taken;
    start = clock();
    selectionSort(arr, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;
}