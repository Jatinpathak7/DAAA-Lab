#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dec_to_bin(char *binary, int n) {
    if (n <= 0) {
        binary[0] = '\0';
        return;
    }
    
    dec_to_bin(binary, n / 2);
    
    // Append the binary digit to the existing string
    int len = strlen(binary);
    binary[len] = (n % 2) + '0';
    binary[len + 1] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s input correctly\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *inputFilename = argv[2];
    char *outputFilename = argv[3];

    FILE *fptr = fopen(inputFilename, "r");
    FILE *fptr2 = fopen(outputFilename, "w");

    if (fptr == NULL || fptr2 == NULL) {
        perror("Error opening file");
        return 1;
    }

    int no;
    while (n > 0 && fscanf(fptr, "%d", &no) == 1) {
        char binary[33] = {0};  // Initialize
        dec_to_bin(binary, no);
        fprintf(fptr2, "%s\n", binary);

        // Print
        printf("%d Number in binary is %s\n", no, binary);

        n--;
    }

    fclose(fptr);
    fclose(fptr2);

    return 0;
}
