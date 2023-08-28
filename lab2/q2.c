#include<stdio.h>
#include<stdlib.h>

int GCD(int a,int b){
    if(b==0){
        return a;
    }
        else {
            return GCD(b,a%b);
        }
}
int main(int argc,char *argv[]){
    FILE *fptr1=fopen(argv[1],"r");
    FILE *fptr2=fopen(argv[2],"w");
    
    int n1,n2;
    while(fscanf(fptr1,"%d %d",&n1,&n2) ==2){
        int result =GCD(n1,n2);
       fprintf(fptr2,"GCD of %d & %d is %d\n",n1,n2,result);
    }
    fclose(fptr1);
    fclose(fptr2);

       return 0;
}
