#include <iostream>
#include <limits.h>
using namespace std;

struct SubArray {
  int low;
  int high;
  int sum;
};

SubArray findMaxCrossingSubArray(int *, int, int, int);
SubArray findMaxSubArray(int *, int, int);

int main() {
  int array[16] = {13, -3, -25, 20, -3,  -16, -23, 18,
                   20, -7, 12,  -5, -22, 15,  -4,  7};
  SubArray maxSubArray;
  int errCode;

  maxSubArray = findMaxSubArray(array, 0, 15);

  errCode = 0;

  if (maxSubArray.low != 7) {
    printf("expected low = %d, but found %d\n", 7, maxSubArray.low);
    errCode = 1;
  }
  if (maxSubArray.high != 10) {
    printf("expected high = %d, but found %d\n", 10, maxSubArray.high);
    errCode = 1;
  }
  if (maxSubArray.sum != 43) {
    printf("expected sum = %d, but found %d\n", 11, maxSubArray.sum);
    errCode = 1;
  }

  if (!errCode) {
    printf("Passed test!\n");
  }
  return errCode;
}

// Finds sub array with maximum sum
SubArray findMaxSubArray(int *array, int low, int high) {
  int mid;
  SubArray subArray, leftSubArray, rightSubArray, crossingSubArray;

  // Base Case of one element
  if (high == low) {
    subArray = {low, high, array[low]};
    return subArray;
  }

  mid = (low + high) / 2;

  // Maximum sum can be in either of three cases:
  // 1. in left sub array
  // 2. in right sub array
  // 3. in crossing sub array that crosses through middle
  leftSubArray = findMaxSubArray(array, low, mid);
  rightSubArray = findMaxSubArray(array, mid + 1, high);
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
SubArray findMaxCrossingSubArray(int *array, int low, int mid, int high) {
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
