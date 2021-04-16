#include "util.h"

class Solution {
    unordered_map<string_view, unordered_map<string_view, bool>> memo;

public:
    bool isScramble(string s1, string s2) {
        return isResult(s1, s2);
    }

    bool isResult(const string_view& s1, const string_view& s2) {
        if (s1.empty())
            return true;
        if (s1.size() == 1)
            return s1[0] == s2[0];
        if (s1.size() == 2)
            return (s1 == s2) ||
                (s1[0] == s2[1] && s1[1] == s2[0]);

        if (memo.count(s1) && memo[s1].count(s2))
            return memo[s1][s2];

        map<char, int> map1;
        map<char, int> map2;
        for (int i = 0; i < s1.size() - 1; ++i) {
            ++map1[s1[i]];
            ++map2[s2[i]];
            if (map1 == map2) {
                int leftLen = i + 1;
                int rightLen = s1.size() - leftLen;
                auto result = isResult(string_view(s1.data(), leftLen),
                                       string_view(s2.data(), leftLen))
                    &&
                    isResult(string_view(s1.data() + leftLen, rightLen),
                             string_view(s2.data() + leftLen, rightLen));
                if (result) {
                    memo[s1][s2] = true;
                    return true;
                }
            }
        }

        map1.clear();
        map2.clear();
        const int size = s1.size();
        for (int i = 0; i < s1.size() - 1; ++i) {
            ++map1[s1[i]];
            ++map2[s2[size - i - 1]];
            if (map2 == map1) {
                int mid = size - i - 1;
                int leftLen = i + 1;
                int rightLen = size - leftLen;
                auto result = isResult(string_view(s1.data(), leftLen), string_view(s2.data() + mid, leftLen))
                    && isResult(string_view(s1.data() + leftLen, rightLen), string_view(s2.data(), rightLen));
                if (result) {
                    memo[s1][s2] = true;
                    return true;
                }
            }
        }
        memo[s1][s2] = false;
        return false;
    }

};
