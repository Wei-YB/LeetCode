#include "util.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);
        return result;
    }

    vector<vector<int>> result;
    vector<int> current;

    void helper(const vector<int>& candidates, int index, int target) {
        if(target == 0){
            result.push_back(current);
            return;
        }
        if(index >= candidates.size())
            return;
        if(target < 0)
            return;

        auto val = candidates[index];
        current.push_back(val);
        helper(candidates, index + 1, target - val);
        current.pop_back();
        int next = index + 1;
        while(next < candidates.size()) {
            if(candidates[next] == candidates[next - 1])
                ++next;
            else
                break;
        }
        helper(candidates, next, target);

        // if(index > 0 && candidates[index] != candidates[index - 1]) {
        //     helper(candidates, index + 1, target);
        // }
    }

};