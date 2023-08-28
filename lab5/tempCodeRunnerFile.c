#include <stdio.h>

int maxSubArraySum(int arr[], int n) {
    int max_so_far = arr[0];
    int max_ending_here = arr[0];
    
    for (int i = 1; i < n; i++) {
        max_ending_here = max_ending_here + arr[i];
        
        if (arr[i] > max_ending_here) {
            max_ending_here = arr[i];
        }
        
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }
    }
    
    return max_so_far;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int maxSum = maxSubArraySum(arr, n);
    printf("The maximum subarray sum is %d\n", maxSum);
    
    return 0;
}