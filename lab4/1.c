#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void merging(int arr[], int l, int m, int r, int *comparisons) {
    int a = m - l + 1;
    int b = r - m;
    int left[a];
    int right[b];

    for (int i = 0; i < a; i++) {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < b; j++) {
        right[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < a && j < b) {
        (*comparisons)++;
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < a) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < b) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int *comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);

        merging(arr, l, m, r, comparisons);
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
    int n = 7000; // Number of elements
    int arr[7000]; // Array for sorting

    randomNumbers("random2.txt", n);
    ascendingNumbers("ascending2.txt", n);
    descendingNumbers("descending2.txt", n);

    while (1) {
        printf("1. ASCENDING\n");
        printf("2. DESCENDING\n");
        printf("3. RANDOM\n");
        printf("4. EXIT\n");

        printf("Enter option: ");
        scanf("%d", &choice);

        char *inputFileName;
        char *outputFileName = "output2.txt";

        switch (choice) {
            case 1:
                inputFileName = "ascending2.txt";
                break;
            case 2:
                inputFileName = "descending2.txt";
                break;
            case 3:
                inputFileName = "random2.txt";
                break;
            case 4:
                printf("Exited...\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
                continue; // Go back to the beginning of the loop
        }

        comparisons = 0;
        readArrayFromFile(inputFileName, arr, n);

        printf("Before Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        clock_t start = clock();
        mergeSort(arr, 0, n - 1, &comparisons);
        clock_t end = clock();

        writeArrayToFile(outputFileName, arr, n);

        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
}
        printf("\n");
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n", time_taken);


        printf("Number of Comparisons: %d\n", comparisons);

        if (comparisons == 0) {
            printf("Scenario: Best-case\n");
        } else {
            printf("Scenario: Worst-case\n");
        }

        printf("\n");
    }

    return 0;
}