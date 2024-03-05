#include "../leetcode.h"

class Solution
{
public:
    bool singleIsIsomorphic(string s, string t)
    {
        char codemap[256];

        for (int i = 0; i < s.length(); i++)
        {
            char m = codemap[s[i]];
            if (m == 0)
            {
                codemap[s[i]] = t[i];
            }
            else if (m != t[i])
            {
                return false;
            }
        }
        return true;
    }

    bool isIsomorphic(string s, string t)
    {
        return singleIsIsomorphic(s, t) && singleIsIsomorphic(t, s);
    }
};

int main2()
{
    Solution s;
    bool r = s.isIsomorphic("foo", "bar");
    r = s.isIsomorphic("egg", "add");
    r = s.isIsomorphic("badc", "baba");

    r = s.isIsomorphic("cpdd", "otdd");
}