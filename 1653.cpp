#include "util.h"
class Solution {
public:
    int minimumDeletions(string s) {
        int cntLeft = 0;
        int cntRight = 0;
        for (auto ch : s)
            if (ch == 'a') ++cntRight;

        int result = cntRight;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'b') {
                ++cntLeft;
            }
            else
                --cntRight;
            result = min(result, cntLeft + cntRight);
        }

        return result;

    }
};