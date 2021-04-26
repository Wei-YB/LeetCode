#include "util.h"

class Solution {
    int limitCheck(int k) {
        int acc = 0, i = 9;
        while(k--) {
            acc += i--;
        }
        return acc;
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k > 9 || n > limitCheck(k))
            return {};
        helper(1, n, k);
        return result;
    }

    vector<vector<int>> result;
    vector<int> current;

    void helper(int i, int remain, int cnt) {
        if(remain == 0 && cnt == 0)
            result.push_back(current);
        else if(remain == 0 || i > 9 || cnt < 0)
            return;
        else {
            current.push_back(i);
            helper(i + 1, remain - i, cnt - 1);
            current.pop_back();
            helper(i + 1, remain, cnt);
        }
    }

};