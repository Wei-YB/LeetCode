#include "util.h"

class Solution {
    unordered_map<int ,int> maps;
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        int result = 0;
        maps[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            if(maps.count(prefix - k)) {
                result += maps[prefix - k];
            }
            maps[prefix]++;
        }
        return result;
    }
};