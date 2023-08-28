#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

void descendingNumbers(char *filename, int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for (int i = n; i > 0; i--) {
        fprintf(file, "%d\n", i);
    }
    fclose(file);
}
void ascendingNumbers(char *filename, int n) {
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
void randomNumbers(char *filename, int n) {
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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
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
    int comparisons;
    int n = 1000;
    int arr[1000];
    randomNumbers("random3.txt", n);
    ascendingNumbers("ascending3.txt", n);
    descendingNumbers("descending3.txt", n);

    while (1) {
        printf("1. ASCENDING\n");
        printf("2. DESCENDING\n");
        printf("3. RANDOM\n");
        printf("4. EXIT\n");

        printf("Enter option: ");
        scanf("%d", &choice);

        char *inputFileName;
        char *outputFileName = "output3.txt";

        switch (choice) {
            case 1:
                inputFileName = "ascending3.txt";
                break;
            case 2:
                inputFileName = "descending3.txt";
                break;
            case 3:
                inputFileName = "random3.txt";
                break;
            case 4:
                printf("Exited...\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
                continue;
        }

        comparisons = 0;
        readArrayFromFile(inputFileName, arr, n);

        printf("Before Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        clock_t start_time = clock();
        quickSort(arr, 0, n - 1, &comparisons);
        clock_t end_time = clock();

        writeArrayToFile(outputFileName, arr, n);

        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Number of Comparisons: %d\n", comparisons);

        if (comparisons <= n * log2(n)) {
    printf("Scenario: Best-case partitioning\n");
} else if (comparisons == ((n * (n - 1)) / 2)) {
            printf("Scenario: Worst-case partitioning\n");
        } else {
            printf("Scenario: Intermediate partitioning\n");
        }

        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n", time_taken);

        printf("\n");
    }

    return 0;
}
