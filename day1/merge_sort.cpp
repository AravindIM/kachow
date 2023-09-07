#include <algorithm>
#include <iostream>
using namespace std;

void mergeSort(int[], int);
void mSort(int[], int, int);
void merge(int[], int, int, int);

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3};
  int errCode = 0;
  int value;
  int size = sizeof(array) / sizeof(int);

  mergeSort(array, size);

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

// function to call the actual recursive function with the right args
void mergeSort(int array[], int size) { mSort(array, 0, size - 1); }

// Uses divide and conquer to sort
// Time Complexity = O(nlogn)
void mSort(int array[], int low, int high) {
  int mid;
  if (low < high) {
    mid = low + (high - low) / 2;
    mSort(array, low, mid);
    mSort(array, mid + 1, high);
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
