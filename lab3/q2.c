#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateDescendingNumbersToFile(char *filename, int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for (int i = n; i >= 1; i--) {
        fprintf(file, "%d\n", i); 
    }
    fclose(file);
}

void generateAscendingNumbersToFile(char *filename, int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for (int i = 1; i <= n; i++) {
        fprintf(file, "%d\n", i); 
    }
    fclose(file);
}

void generateRandomNumbersToFile(char *filename, int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", rand() % 1000 + 1); 
    }
    fclose(file);
}

int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}
void readArrayFromFile(char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

void writeArrayToFile(char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
}

int main() {
    int choice;
    int randomArr[1000];
    int ascendingArr[1000];
    int n = 1000;

    generateRandomNumbersToFile("random.txt", n);
    generateAscendingNumbersToFile("ascending.txt", n);
    generateDescendingNumbersToFile("descending.txt", n);

    while (1) {
        printf("ASCENDING\n");
        printf("DESCENDING\n");
        printf("RANDOM\n");
        printf("EXIT\n");

        printf("Enter option\n");
        scanf("%d", &choice);  // Remove the unnecessary \n in the format specifier

        char *inputFileName;
        char *outputFileName = "output.txt";
        int arr[10000];
        int arraySize = 1000;  // Renamed to arraySize to avoid conflict
        switch (choice) {
            case 1:
                inputFileName = "ascending.txt";
                break;
            case 2:
                inputFileName = "descending.txt";
                break;
            case 3:
                inputFileName = "random.txt";
                break;
            default:
                printf("Exitted......\n");
                exit(1);  
        }
        readArrayFromFile(inputFileName, arr, arraySize);
        
        printf("Before Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        clock_t start_time = clock();
        int comparisons = insertionSort(arr, n);
        clock_t end_time = clock();
        
        writeArrayToFile(outputFileName, arr, n);
        
        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        printf("Number of Comparisons: %d\n", comparisons);
        
        if (comparisons == 0) {
            printf("Scenario: Best-case\n");
        } 
        else{
            printf("Scenario: Worst-case\n");
        }
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n", time_taken);
        
        printf("\n");
    }
    return 0;
}