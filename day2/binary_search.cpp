#include <iostream>

using namespace std;

int binarySearch(int[], int, int, int);

int main() {
  int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int search = 3;
  int invalidSearch = 13;
  int index;
  int errCode = 0;

  index = binarySearch(array, search, 0, 9);

  if (index != search) {
    cout << "expected index to be " << search << " but found " << index << endl;
    errCode = 1;
  }

  index = binarySearch(array, invalidSearch, 0, 9);

  if (index != -1) {
    cout << "expected index to be -1 but found " << index << endl;
    errCode = 1;
  }

  if (errCode != 1) {
    cout << "Passed Tests!" << endl;
  }

  return errCode;
}

int binarySearch(int array[], int search, int low, int high) {
  int mid = low + (high - low) / 2;

  if (low > high) {
    return -1;
  }
  if (array[mid] == search) {
    return mid;
  } else if (array[mid] < search) {
    return binarySearch(array, search, mid + 1, high);
  }

  return binarySearch(array, search, low, mid - 1);
}
