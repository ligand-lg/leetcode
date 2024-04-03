#include "../leetcode.h"

class Solution {
public:
  int hIndex(vector<int> &citations, size_t start, size_t end) {
    // 递归出口
    if (start == end) {
      if (citations[start] >= citations.size() - start) {
        return citations.size() - start;
      } else {
        return 0;
      }
    }

    size_t mid = (start + end) / 2;
    // 递归循环
    if (citations[mid] >= citations.size() - mid) {
      return hIndex(citations, start, mid);
    } else {
      return hIndex(citations, mid + 1, end);
    }
  }

  int hIndex(vector<int> &citations) {
    return hIndex(citations, 0, citations.size() - 1);
  }
};

/*
对于下标为i的元素，定义Ni为以它为开始，到最末尾的元素个数，即Ni=size() - i,
这里的i是下标，从0开始。
根据h-index的定义，Ni为h-index的必要条件是，citations[i] >=
Ni.找到最大的Ni，就是h-index的值。

如何找到最大的Ni？有两种方法：全遍历和二分查找。
全遍历：
    遍历所有的元素，找到最大的Ni， 时间复杂度
o（n）。有个改良思路是，因为是找最大的Ni，而从左到右的顺序Ni从大到小的顺序，
    此时遍历元素的个数为
n-h，当然h远小于n时候，特别极端的情况下，h为0是，就等价于改良前，也就是o（n）

二分查找：
    通过上面的全遍历的改良，可以发现，可能的h-index，也就是Ni排列是有规律的，即从第一个满足条件的Ni开始，往右都是
    符合条件的。而这个第一个Ni，就是h-index。这时候就是可以使用二分查找了，基本思路：
        在当前给定的start，end下，对于中间的元素mid，
            如果mid符合h-index的条件，那保留[start, mid]。因为mid
已经是可能的解，所以往左走，尝试寻找更优的解。
            如果mid不符合h-index的条件，那保留[mid+1,end]，尝试在右边找到可能的解。
    在考虑下查找终止情况：
        只有两个元素的情况，考虑c++除法是向下取整，因此mid=start，因此无论mid是否符合条件，都会转变为只有一个元素的情况。因此不用特殊考虑。
        只有一个元素的情况，直接判断即可。
        没有元素的情况
            因为初始条件给出元素个数最少为1
            当元素情况大于0时，进过以上迭代不可能出现元素为0的情况
            综合就是，不存在没有元素的情况
    综合整个二分法，最终有：
        特例1：只有一个元素，判断当前元素符合h-index定义。如果符合，答案就是n；如果不符合，则答案就是0.
        正常情况：取元素mid = (start+end)/2, 如果mid 符合 h-index，则返回[start,
mid]的结果，否则返回[mid+1, end]的结果。
*/
