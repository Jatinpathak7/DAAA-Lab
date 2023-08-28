#include <stdio.h>
#include <stdlib.h>

int binarySearchIteration(int arr[], int size, int target, int *comparisons)
{
    int left = 0;
    int right = size - 1;
    int res = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        if (arr[mid] == target)
        {
            res = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}
int binarySearchRecursion(int arr[],int l, int r, int target, int *comparisons){
           
        if (r >= l) {
        int mid = l + (r - l) / 2;
        (*comparisons)++;

        if (arr[mid] == target){
            return mid;
        }
        if(arr[mid]>target){
            return binarySearchRecursion(arr,l,mid-1,target,comparisons);
        }
        if(arr[mid]<target){
            return binarySearchRecursion(arr,mid+1,r,target,comparisons);
        }
        }
        return -1;

}
int main()
{
    int arr[] = {1,4,9,12,13,21};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 13;
    int comparisons = 0;
    int comparisons2 = 0;
    int pos = binarySearchIteration(arr, size, target, &comparisons);
    printf("Element %d found at %d by using iteration\n", target, pos);
    printf("%d comparisons made\n", comparisons);
    int res2=binarySearchRecursion(arr,0,size-1,target,&comparisons2);
    printf("Element %d found at %d by using recursion\n", target, res2);
    printf("%d comparisons made\n", comparisons2);
    return 0;
}