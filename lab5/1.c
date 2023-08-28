
#include <stdio.h>
#include <limits.h>

int main()
{
   int n;
   printf("Enter size of array");
   scanf("%d", &n);

   int arr[20];
   printf("Enter elements of array");
   for(int i=0; i<n; i++){
     scanf("%d", &arr[i]);
   }

   int max_sum = 0, curr_sum =0;

   for(int i=0; i<n; i++){

      curr_sum += arr[i];

      if(max_sum < curr_sum)
        max_sum = curr_sum;

      if(curr_sum < 0)
        curr_sum = 0;

}

   printf("%d ", max_sum);

   return 0;
}