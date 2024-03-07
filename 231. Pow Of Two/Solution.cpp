#include "../leetcode.h"

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {          
            return false;
        }

        int cnt = 0;
        for (int i = 0; i < 31; i++)
        {
            cnt += n >> i & 1;
        }
        return cnt == 1;
    }
};

int main() {
    Solution s;
    bool res = s.isPowerOfTwo(1);
    cout<<res;

}