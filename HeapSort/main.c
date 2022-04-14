#include <stdio.h>
#include <stdlib.h>

  void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
  }

  void heapify(int arr[], int n, int i) {

    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[root])
      root = left;

    if (right < n && arr[right] > arr[root])
      root = right;

    if (root != i) {
      swap(&arr[i], &arr[root]);
      heapify(arr, n, root);
    }
  }

  void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      heapify(arr, i, 0);
    }
  }

  void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }

  // Driver code
  int main() {

    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    for (i = 0; i<n; i++)
    {
      printf("a[%d] = ", i);
      scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("Sorted array is \n");
    printArr(arr, n);
  }
