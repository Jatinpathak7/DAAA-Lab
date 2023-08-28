#include <stdio.h>
#include <stdlib.h>

void findNumber(int arr[], int n) {
    int smallest = arr[0];
    int largest = arr[0];
    int s_smallest;
    int s_largest;

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            s_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < s_smallest) {
            s_smallest = arr[i];
        }

        if (arr[i] > largest) {
            s_largest = largest;
            largest = arr[i];
        } else if (arr[i] > s_largest) {
            s_largest = arr[i];
        }
    }

    printf("Second smallest element is %d\n", s_smallest);
    printf("Second largest element is %d\n", s_largest);
}


int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    findNumber(arr, n);

    free(arr); // Don't forget to free allocated memory

    return 0;
}

