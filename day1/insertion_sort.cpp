#include <iostream>
using namespace std;

void insertionSort(int[], int);

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3};
  int errCode = 0;
  int value;
  insertionSort(array, 6);

  for (int i = 0; i < 6; i++) {
    value = i + 1;
    if (array[i] != value) {
      cout << "expected array[" << value << "] = " << i << ", but got "
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
