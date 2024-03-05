#include "../leetcode.h"

class Solution
{
private:
    int n, num;
    vector<int> res;
    bool placeholder[65536];

private:
    bool back_tracking()
    {
        if (res.size() >= num)
        {
            return true;
        }

        int pre = res.back();
        int next = -1;
        for (int i = 0; i < n; i++)
        {
            next = pre ^ (1ul << i); // 异或（xor）用于bit 翻转

            if (!placeholder[next])
            {
                res.push_back(next);
                placeholder[next] = true;
                if (back_tracking())
                {
                    return true;
                }
                else
                {
                    res.pop_back();
                    placeholder[next] = false;
                }
            }
        }

        return false;
    }

public:
    vector<int> grayCode(int n)
    {
        this->n = n;
        this->num = pow(2, n);
        res.reserve(size_t(this->num));

        res.push_back(0);
        placeholder[0] = true;

        back_tracking();
        return res;
    }
};

int main(int, char **)
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