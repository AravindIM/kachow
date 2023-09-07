#include <iostream>

using namespace std;

void countSort(int[], int);

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3};
  int errCode = 0;
  int value;
  int size = sizeof(array) / sizeof(int);

  countSort(array, size);

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

// count sort assumes numbers are positive
// Time Complexity = O(n)
// Not very memory efficient as it creates
// count array of size of maximum elements
void countSort(int array[], int size) {
  int max, *buffer, *count;

  buffer = new int[size];
  max = array[0];

  // copy the array to a buffer
  // and also get size of the count array
  // as maximum number + 1
  for (int i = 0; i < size; i++) {
    buffer[i] = array[i];
    if (array[i] > max) {
      max = array[i];
    }
  }

  // create array to hold number of elements
  // less than or equal to the current element
  count = new int[max + 1];

  for (int i = 0; i <= max; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = 0; i < size; i++) {
    array[count[buffer[i]] - 1] = buffer[i];
    count[buffer[i]]--;
  }

  delete[] buffer;
  delete[] count;
}
