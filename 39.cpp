#include "util.h"

class Solution {
public:

    vector<vector<int>> result;
    vector<int> current;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, 0, target);
        return result;
    }

    void helper(const vector<int>& candidates, int index, int target) {
        if(target == 0) {
            result.push_back(current);
            return;
        }
        if(index >= candidates.size()) {
            // out of range;
            return;
        }
        int mark = target;
        int cnt = 0;
        int val = candidates[index];
        while (mark >= 0) {
            helper(candidates, index + 1, mark);
            current.push_back(val);
            mark -= val;
            ++cnt;
        }
        while(cnt) {
            --cnt;
            current.pop_back();
        }
    }
};

int main() {
    auto data = test::get_vec_data("[2,3,6,7]");
    Solution s;
    auto ret = s.combinationSum(data, 7);
    test::print_matrix(ret);
}