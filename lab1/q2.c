#include <stdio.h>
#include <stdlib.h>

void findSum(int arr[], int n, int prefixS[]) {
    prefixS[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixS[i] = prefixS[i-1] + arr[i];
    }
}

int main() {
    const int n;
    printf("Size of array:");
    scanf("%d", &n);
int *arr = (int *)malloc(n * sizeof(int)); 
int *prefixS = (int *)malloc(n * sizeof(int)); 
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50;
        printf("%d ", arr[i]);
    }

    findSum(arr, n, prefixS);

    printf("\nPrefix array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixS[i]);
    }

    return 0;
}
