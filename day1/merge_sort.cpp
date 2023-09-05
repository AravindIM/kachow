#include <algorithm>
#include <iostream>
using namespace std;

void mergeSort(int[], int, int);
void merge(int[], int, int, int);

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3};
  int errCode = 0;
  int value;
  mergeSort(array, 0, 6);

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

void mergeSort(int array[], int low, int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, mid, high);
  }
}

void merge(int array[], int low, int mid, int high) {
  int leftSize = mid - low + 1;
  int rightSize = high - mid;
  int l, r, m;

  int *left = new int[leftSize];
  int *right = new int[rightSize];

  for (int i = 0; i < leftSize; i++) {
    left[i] = array[low + i];
  }

  for (int i = 0; i < rightSize; i++) {
    right[i] = array[mid + 1 + i];
  }

  l = 0;
  r = 0;
  m = low;

  while (l < leftSize && r < rightSize) {
    if (left[l] <= right[r]) {
      array[m] = left[l];
      l++;
    } else {
      array[m] = right[r];
      r++;
    }
    m++;
  }

  while (l < leftSize) {
    array[m] = left[l];
    l++;
    m++;
  }

  while (r < rightSize) {
    array[m] = right[r];
    r++;
    m++;
  }

  delete[] left;
  delete[] right;
}
