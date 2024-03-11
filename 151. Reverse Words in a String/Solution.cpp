#include "../leetcode.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss;

        int i, j;
        // init i, j;
        i = s.length() - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i -= 1;
        }
        j = i;

        while (i >= 0)
        {
            while (i >= 0 && s[i] != ' ')
            {
                i -= 1;
            }
            if (j > i)
            {
                ss << s.substr(i + 1, j - i) << " ";
            }

            while (i >= 0 && s[i] == ' ')
            {
                i -= 1;
            }
            j = i;
        }

        string res = ss.str();
        if (res.length() > 0)
        {
            res = res.substr(0, res.length() - 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    string ss = s.reverseWords("  hello  world  ");
    ss = s.reverseWords("  ");
    ss = s.reverseWords("hello");

    cout << ss;
}