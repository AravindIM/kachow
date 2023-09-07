#include <iostream>
using namespace std;

void quickSort(int[], int);
void qSort(int[], int, int);
int partition(int[], int, int);

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3};
  int errCode = 0;
  int value;
  quickSort(array, 6);

  for (int i = 0; i < 6; i++) {
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

// quickSort function that calls the actual function with the right
// parameters
void quickSort(int array[], int size) { qSort(array, 0, size - 1); }

// Expected run time is nlogn
// Worst case Time Complexity O(n^2)
void qSort(int array[], int low, int high) {
  int pivotIndex;

  if (low < high) {
    // find pivot index after placing pivot position in right position
    pivotIndex = partition(array, low, high);
    // sort everything before the pivot index
    qSort(array, low, pivotIndex - 1);
    // sort everything after the pivot index
    qSort(array, pivotIndex + 1, high);
  }
}

int partition(int array[], int low, int high) {
  int pivot, lhsOfPivot, temp, pivotIndex;

  // we pick the pivot element as the last element
  pivot = array[high];

  // we start from left most tip of the array
  // we use this variable to demarcate partially sorted lhs
  lhsOfPivot = low - 1;

  // put elements lesser than pivot to the left
  // lhsOfPivot points to portion where everything
  // on the index and left of it is lesser than pivot
  for (int i = low; i < high; i++) {
    if (array[i] <= pivot) {
      lhsOfPivot++;
      temp = array[lhsOfPivot];
      array[lhsOfPivot] = array[i];
      array[i] = temp;
    }
  }

  // pivot index is on the right of lhs
  pivotIndex = lhsOfPivot + 1;

  // place the pivot in the right position
  // by swapping it with the element in the position pointed by
  // pivot index
  array[high] = array[pivotIndex];
  array[pivotIndex] = pivot;

  return pivotIndex;
}
