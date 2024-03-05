#include "../leetcode.h"


struct X {
    int v, index;
    bool operator<(const X& val) const {
        if(val.v == v) {
            return index < val.index;
        }
        return v < val.v;
    }
};


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<X> tmp;

        tmp.reserve(nums.size());
        for (int i=0; i < nums.size(); i++) {
            X x = X();
            x.index = i;
            x.v = nums[i];
            tmp.push_back(x);
        }

        sort(tmp.begin(), tmp.end());

        for (int i =0; i < tmp.size()-1; i++) {
            if (tmp[i].v == tmp[i+1].v) {
                if ((tmp[i+1].index - tmp[i].index) <= k) {
                    return true;
                }
            }
        }
        return false;    
    }
};

int main() {
    Solution s;

    vector<int> data{1,2,3,1};
    int k = 3;

    bool res = s.containsNearbyDuplicate(data, k);
    cout<<res;
    return 0;
}