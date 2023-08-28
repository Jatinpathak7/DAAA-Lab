#include <stdio.h>
#include <stdlib.h>

int t_duplicates(int arr[], int n) {
    int duplicates = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                duplicates++;
                break;
            }
        }
    }
    return duplicates;
}

// Function to find the most repeating element in the array
int most_rep_element(int arr[], int n) {
    int max = 0;
    int most_rep = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > max) {
            max = count;
            most_rep = arr[i];
        }
    }
    return most_rep;
}

int main() {
    int n;
    printf("Enter the number of elements of array");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int)); 
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 20;
    }

    printf("array:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int dups = t_duplicates(arr, n);
    printf("Total number of duplicate values: %d\n", dups);
    int most_rep = most_rep_element(arr, n);
    printf("the most repeating element in the array: %d\n", most_rep);
    return 0;
}