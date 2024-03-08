#include "../leetcode.h"

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        int res[101] = {0}; // res[i] == 1 表示，s1的前i个元素和s2的前k-i个元素，是s3前k个元素的interleaving
        int tmp[101] = {0};

        int k = 0; // k 表示 s3 当前的长度。当 k = 0时，i = 0 是成立的。
        res[0] = 1;

        k = 1;
        bool find_ans = true;
        while (find_ans && k <= s3.length())
        {
            find_ans = false;
            copy(begin(res), end(res), begin(tmp));

            for (int i = 0; i <= s1.length() && i <= k; i++)
            {
                if (tmp[i] == 1)
                {
                    res[i] = 0; // old i
                    if (i < s1.length() && s1[i + 1 - 1] == s3[k - 1])
                    {
                        res[i + 1] = 1;
                        find_ans = true;
                    }
                    int j = k - i; // new j
                    if (j <= s2.length() && s2[j - 1] == s3[k - 1])
                    {
                        res[i] = 1;
                        find_ans = true;
                    }
                }
            }
            k += 1;
        }

        return find_ans;
    }
};

int main() {
    Solution s;
    bool res = s.isInterleave("aabcc", "dbbca" ,"aadbbcbcac");
    cout << res;
}