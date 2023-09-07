#include <iostream>
#include <limits.h>
using namespace std;

struct SubArray {
  int low;
  int high;
  int sum;
};

SubArray findMaxSubArray(int[], int);
SubArray recurseMaxSubArray(int[], int, int);
SubArray findMaxCrossingSubArray(int[], int, int, int);

int main() {
  int array[16] = {13, -3, -25, 20, -3,  -16, -23, 18,
                   20, -7, 12,  -5, -22, 15,  -4,  7};
  SubArray maxSubArray;
  int errCode;
  int size = sizeof(array) / sizeof(int);

  maxSubArray = findMaxSubArray(array, size);

  errCode = 0;

  if (maxSubArray.low != 7) {
    cout << "expected low = 7, but found " << maxSubArray.low << endl;
    errCode = 1;
  }
  if (maxSubArray.high != 10) {
    cout << "expected high = 10, but found " << maxSubArray.high << endl;
    errCode = 1;
  }
  if (maxSubArray.sum != 43) {
    cout << "expected sum = 11, but found " << maxSubArray.sum << endl;
    errCode = 1;
  }

  if (!errCode) {
    cout << "Passed test!" << endl;
  }
  return errCode;
}

// function that calls the actual recursive function with right args
SubArray findMaxSubArray(int array[], int size) {
  return recurseMaxSubArray(array, 0, size - 1);
}

// Finds sub array with maximum sum
// Takes O(nlogn)
// Normal Brute force takes O(n^2)
// n for the for loops ran for each time inside the max crossing sub array
// function logn for number of execution of that function with division
SubArray recurseMaxSubArray(int array[], int low, int high) {
  int mid;
  SubArray subArray, leftSubArray, rightSubArray, crossingSubArray;

  // Base Case of one element
  if (high == low) {
    subArray = {low, high, array[low]};
    return subArray;
  }

  mid = low + (high - low) / 2;

  // Maximum sum can be in either of three cases:
  // 1. in left sub array
  // 2. in right sub array
  // 3. in crossing sub array that crosses through middle
  leftSubArray = recurseMaxSubArray(array, low, mid);
  rightSubArray = recurseMaxSubArray(array, mid + 1, high);
  crossingSubArray = findMaxCrossingSubArray(array, low, mid, high);

  // Check which is the maximum of the three cases
  if (leftSubArray.sum >= rightSubArray.sum &&
      leftSubArray.sum >= crossingSubArray.sum) {
    return leftSubArray;
  } else if (rightSubArray.sum >= leftSubArray.sum &&
             rightSubArray.sum >= crossingSubArray.sum) {
    return rightSubArray;
  }

  return crossingSubArray;
}

// Finds sub array crossing through middle having maximum sum
// Takes O(n) time
SubArray findMaxCrossingSubArray(int array[], int low, int mid, int high) {
  int leftSum, maxLeft, sum, rightSum, maxRight, maxSum;
  SubArray subArray;

  // Calcute the maximum sum from mid to low
  // Find the leftmost point of the maximum sum

  leftSum = INT_MIN;
  maxLeft = mid;
  sum = 0;

  for (int i = mid; i >= low; i--) {
    sum += array[i];
    if (sum > leftSum) {
      leftSum = sum;
      maxLeft = i;
    }
  }

  rightSum = INT_MIN;
  maxRight = mid + 1;
  sum = 0;

  // Calcute the maximum sum from mid + 1 to high
  // Find the rightmost point of the maximum sum

  for (int j = mid + 1; j <= high; j++) {
    sum += array[j];
    if (sum > rightSum) {
      rightSum = sum;
      maxRight = j;
    }
  }

  maxSum = leftSum + rightSum;

  subArray = {maxLeft, maxRight, maxSum};
  return subArray;
}
