#include <iostream>

using namespace std;

void bubbleSort(int[], int);

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3};
  int errCode = 0;
  int value;
  bubbleSort(array, 6);

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

// Sort array by swapping nearby elements
// till the smallest gets to the left
// then repeat for the rest of array
// time complexity of O(n^2)
void bubbleSort(int array[], int size) {
  int temp;

  // i - 1 marks the sorted part of array
  // last two elements will be swapped at the end
  for (int i = 0; i < size - 1; i++) {
    // j used to swap the elements of unsorted part of array
    for (int j = size - 1; j > i; j--) {
      if (array[j] < array[j - 1]) {
        temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
      }
    }
  }
}
