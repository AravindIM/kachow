#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
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
