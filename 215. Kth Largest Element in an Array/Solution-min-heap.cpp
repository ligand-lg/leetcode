//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(n log(k))
 * S(n) = O(k)
 */


#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<>> heap;
    int size = nums.size();
    int i = 0;

    for (; i < k; i++)
      heap.push(nums[i]);

    for (; i < size; i++) {
      if (nums[i] > heap.top()) {
        heap.push(nums[i]);
        heap.pop();
      }
    }
    return heap.top();
  }
};
