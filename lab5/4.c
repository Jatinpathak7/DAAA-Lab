#include <stdio.h>
#include <math.h>

void round_matrix(int n, float **A) {
  // Find the minimum and maximum values of the elements of A.
  float min_val = A[0][0];
  float max_val = A[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] < min_val) {
        min_val = A[i][j];
      }
      if (A[i][j] > max_val) {
        max_val = A[i][j];
      }
    }
  }

  // For each element aij of A, do the following:
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] < min_val) {
        A[i][j] = floor(A[i][j]);
      } else if (A[i][j] > max_val) {
        A[i][j] = ceil(A[i][j]);
      }
    }
  }
}

int main() {
  float A[3][3] = {
      {1.1, 2.2, 3.3},
      {4.4, 5.5, 6.6},
      {7.7, 8.8, 9.9},
  };

  round_matrix(3, A);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%.1f ", A[i][j]);
    }
    printf("\n");
  }

  return 0;
}