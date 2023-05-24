#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void save(int *arr, int size) {
  FILE *fptr;
  fptr = fopen("output.txt", "w");
  if (fptr == NULL) {
    printf("Ошибка при открытии файла");
    exit(1);
  }
  for (int i = 0; i < size; i++) {
    fprintf(fptr, "%d\n", arr[i]);
  }
  fclose(fptr);
}

int bubbleSort(float *num, int size) {
  int swaps = 0;
  for (int i = 0; i < size - 1; i++) {
    for (int j = (size - 1); j > i; j--) {
      if (fabs(num[j - 1] - num[j]) > 1e-7 && num[j - 1] > num[j]) {
        float temp = num[j - 1];
        num[j - 1] = num[j];
        num[j] = temp;
        swaps += 1;
      }
    }
  }
  return swaps;
}

int main() {
  int length = 1000;
  int count = 10000;
  int total[count];
  srand(time(NULL));
  for (int k = 0; k < count; k++) {
    float array[length];
    for (int i = 0; i < length; i++) {
      int random_int = rand() % 100001;
      float random_float = random_int / 1000.0;
      array[i] = random_float;
    }
    total[k] = bubbleSort(array, length);
  }
  save(total, count);
  return 0;
}
