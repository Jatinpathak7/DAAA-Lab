#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxDiff = arr[1] - arr[0];
    int minElement = arr[0]; 

    for (int j = 1; j < n; j++) {
        if (arr[j] - minElement > maxDiff) {
            maxDiff = arr[j] - minElement;
        }

        if (arr[j] < minElement) {
            minElement = arr[j];
        }
    }

    printf("The largest difference is: %d\n", maxDiff);

    return 0;
}
