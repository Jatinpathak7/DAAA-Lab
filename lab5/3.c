#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    if (n < 2) {
        printf("Error: Please enter n greater than or equal to 2.\n");
        return 1;
    }
    int arr[20];
    printf("Enter numbers\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int res1 = arr[0];
    int res2 = arr[0];
    for (int i = 1; i < n; i++) {
        res1 = gcd(res1, arr[i]);
        res2 = lcm(res2, arr[i]);
    }
    printf("GCD of numbers = %d\n", res1);
    printf("LCM of numbers = %d\n", res2);
    return 0;
}
