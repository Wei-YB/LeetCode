#include "util.h"
class Solution {
    unordered_map<int, int> maps;
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int prefix = 0;
        int result = 0;
        maps[0] = 1;

        for(int i = 0; i < A.size(); ++i) {
            prefix += A[i];
            auto target = prefix % K;
            if(target < 0)
                target += K;
            auto it = maps.find(target);
            result += it == maps.end() ? 0 : it->second;
            maps[target]++;
        }

        return result;
    }
};