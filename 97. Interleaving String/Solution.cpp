#include "../leetcode.h"

class Solution
{
    string _s1, _s2, _s3;

public:
    bool _isInterLeave(int i1, int i2, int i3, int preMatch)
    {
        if (i3 == _s3.length()) {
            return true;
        }
        
        // try match s1
        if (preMatch != 1)
        {
            int j1 = i1, j2 = i2, j3 = i3;
            while (_s3[j3] == _s1[j1])
            {
                if (_isInterLeave(j1 + 1, j2, j3 + 1, 1))
                {
                    return true;
                }
                j1 += 1;
                j3 += 1;
                if (j3 == _s3.length())
                {
                    return true;
                }
            }
        }

        // try match s2
        if (preMatch != 2)
        {
            int j1 = i1, j2 = i2, j3 = i3;
            while (_s3[j3] == _s2[j2])
            {
                if (_isInterLeave(j1, j2 + 1, j3 + 1, 2))
                {
                    return true;
                }
                j2 += 1;
                j3 += 1;

                if (j3 == _s3.length())
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
        {
            return false;
        }
        if (s1.length() == 0)
        {
            return s2 == s3;
        }
        if (s2.length() == 0)
        {
            return s1 == s3;
        }

        _s1 = s1;
        _s2 = s2;
        _s3 = s3;

        return _isInterLeave(0, 0, 0, 0);
    }
};

int main()
{
    Solution s;
    bool res = s.isInterleave("a", "a", "aa");
    cout << res;
}