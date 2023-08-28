#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    FILE *fptr;
    fptr = fopen("C:/Users/KIIT/files/lab2example.txt","w");
    if(fptr == NULL){
        printf("Error");
        exit(1);
    }
    printf("Enter num:");
    scanf("%d",&num);
    fprintf(fptr,"%d",num);
    fclose(fptr);
     fptr = fopen("C:/Users/KIIT/files/lab2example.txt", "r");
     char myString[100];
     fgets(myString, 100, fptr);
     printf("%s",myString);
     fclose(fptr);
    return 0;
}