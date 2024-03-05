#include "../leetcode.h"

class Solution
{
private:
    vector<int> res;

private:
    bool only_one_bit_differ(int a, int b, int n) {
        int differ_num = 0;
        int xor_a_b = a ^ b;
        for (int i = 0; i < n; i++){
            if (xor_a_b == 1 << i) {
                return true;
            }
        }
        return false;
    }

    void back_tracking(int left_index, int right_index, int n)
    {
        if (right_index - left_index == 1) {
            return;
        }

        int mid_index = (right_index - left_index + 1) / 2 + left_index;
        back_tracking(left_index, mid_index-1, n);
        back_tracking(mid_index, right_index, n);

        if (!only_one_bit_differ(res[mid_index-1], res[mid_index], n)) {
            reverse(res.begin()+mid_index, res.begin()+right_index+1); // reverse 右边是开区间
        }
    }

public:
    vector<int> grayCode(int n)
    {
        
        int num = pow(2, n);
        res.reserve(num);
        for (int i = 0; i < num; i++){
            res.push_back(i);
        }
        back_tracking(0, num-1, n);
        return res;
    }
};

int main2(int, char **)
{
    Solution s;
    vector<int> res = s.grayCode(5);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl
         << "end";
    return 0;
}