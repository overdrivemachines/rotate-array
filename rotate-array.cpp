#include <iostream>
#include <vector>

using namespace std;

void printv(vector<int> &nums) {
  for (auto n : nums) {
    cout << n << " ";
  }
  cout << endl;
}


void rotate_old(vector<int>& nums, int k) {
  // printv(nums);

  int nums_length = nums.size();
  vector<int> v;

  if ((nums_length <= 1) || (nums_length == k))
    return;

  if (k > nums_length) {
    k = k % nums_length;
  }

  if (k == 0)
    return;

  // if k < nums.length()

  for (int i = 0; i < k; i++) {
    v.push_back(nums[i]);
    nums[i] = nums[nums_length - k + i];
  }

  for (int i = nums_length - 1; i >= k*2; i--) {
    nums[i] = nums[i - k];
  }

  for (int i = k; i < k*2; i++) {
    nums[i] = v[i - k];
  }


  // printv(nums);
        
}

void rotate(vector<int>& nums, int k) {
  // printv(nums);

  int nums_length = nums.size();
  vector<int> v;

  if ((nums_length <= 1) || (nums_length == k))
    return;

  if (k > nums_length) {
    k = k % nums_length;
  }

  if (k == 0)
    return;

  // get the lask k integers in nums
  for (int i = nums_length - k; i < nums_length; i++) {
    v.push_back(nums[i]);
  }

  // printv(v);

  // move each elements back by k
  for (int i = nums_length - 1; i >= k; i--) {
    nums[i] = nums[i - k];
  }

  for (int i = 0; i < k; i++)
    nums[i]  = v[i];

  // printv(nums);
        
}

int main(int argc, char const *argv[]) {
  vector<int> numbers = {-1, -100, 3, 99};
  int steps = 3;
  // Output: [10,11,12,1,2,3,4,5,6,7,8,9]

  // 10,11,12,4,5,6,7,8,9,10,11,12
  // v = 1,2,3

  // 1,2,3,4,5 k = 5
  // 5,1,2,3,4  1
  // 4,5,1,2,3  2
  // 3,4,5,1,2  3
  // 2,3,4,5,1  4
  // 1,

  // [-1,-100,3,99], k = 3
  // 99,-1,-100,3
  // 3,99,-1,-100
  // -100,3,99,-1

  rotate(numbers, steps);
  return 0;
}
