#include <iostream>
using namespace std;

void insertionSort(int[], int);

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3};
  int errCode = 0;
  int value;
  int size = sizeof(array) / sizeof(int);

  insertionSort(array, size);

  for (int i = 0; i < size; i++) {
    value = i + 1;
    if (array[i] != value) {
      cout << "expected array[" << i << "] = " << value << ", but got "
           << array[i] << endl;
      errCode = 1;
    }
  }

  if (!errCode) {
    cout << "Passed tests!" << endl;
  }

  return errCode;
}

void insertionSort(int array[], int size) {
  int key, i, j;
  for (i = 1; i < size; i++) {
    key = array[i];

    j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = key;
  }
}
