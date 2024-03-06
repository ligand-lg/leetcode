#include "../leetcode.h"

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;

        if (nums.size() == 0)
        {
            return res;
        }

        int range_start_index = 0;
        int i = 1;
        while (i < nums.size())
        {
            if (int64_t(nums[i]) - int64_t(nums[i - 1])!= 1)
            {
                int range_end_index = i - 1;
                char buff[32];
                if (range_start_index == range_end_index)
                {
                    snprintf(buff, sizeof(buff), "%d", nums[range_start_index]);
                }
                else
                {
                    snprintf(buff, sizeof(buff), "%d->%d", nums[range_start_index], nums[range_end_index]);
                }
                //  string buffAsStdStr = buff;
                res.push_back(string(buff));
                range_start_index = i;
            }
            i += 1;
        }
        // last one range
        int range_end_index = nums.size() - 1;
        char buff[32];
        if (range_start_index == range_end_index)
        {
            snprintf(buff, sizeof(buff), "%d", nums[range_start_index]);
        }
        else
        {
            snprintf(buff, sizeof(buff), "%d->%d", nums[range_start_index], nums[range_end_index]);
        }
        res.push_back(string(buff));

        return res;
    }
};

int main() {
    Solution s;
    vector<int> d{2147483647, -2147483647};
    vector<string> res = s.summaryRanges(d);
    cout << endl;
}