#include "../leetcode.h"

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> tokens;

        int i = 0;
        while (i < path.size())
        {
            int token_start, token_end;

            while (i < path.size() && path[i] == '/')
            {
                i += 1;
            }
            if (i < path.size())
            {
                token_start = i;

                int j = i + 1;
                while (j < path.size() && path[j] != '/')
                {
                    j += 1;
                }
                token_end = j - 1;
                i = j;

                string token = path.substr(token_start, token_end - token_start+1);
                // special  token
                if (token == ".")
                {
                    // do nothing, skip token
                }
                else if (token == "..")
                {
                    if (tokens.size() > 0)
                    {
                        tokens.pop_back();
                    }
                }
                else
                {
                    tokens.push_back(token);
                }
            }
        }
        if (tokens.size() == 0)
        {
            return "/";
        }

        stringstream ss;
        for (int k = 0; k < tokens.size(); k++)
        {
            ss << "/" << tokens[k];
        }
        return ss.str();
    }
};

int main()
{
    Solution s;
    string res = s.simplifyPath("/home/");
    res = s.simplifyPath("/../");
    res = s.simplifyPath("/home//foo/");
    res = s.simplifyPath("/home///foo////./..//.../");
    cout << res;
}