#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int largest = INT_MIN;
    int num;
    int k = 0;
    vector<int>::iterator iter = nums.begin();
    while (iter < nums.end()) {
      num = *iter;
      if (num > largest) {
        largest = num;
        k++;
        iter++;
      } else if (num == largest) {
        nums.erase(iter);
      }
    }
    return k;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 4, 5, 6, 6, 6, 6, 7, 8};
  Solution s = Solution();
  int k = s.removeDuplicates(nums);
  int num;
  vector<int>::iterator iter = nums.begin();
  vector<int>::iterator end = nums.end();
  while (iter < end) {
    num = *iter;
    cout << num << ",";
    iter++;
  }
  cout << endl;
  cout << k << endl;
  return 0;
}
