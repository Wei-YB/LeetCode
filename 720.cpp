#include "util.h"

class Solution {
    map<int, set<string>> trie;
public:
    string longestWord(vector<string>& words) {
        for(auto& str : words) {
            trie[str.size()].insert(str);
        }

        for(auto it = trie.rbegin(); it != trie.rend(); ++it) {
            auto& strs = it->second;
            auto len = it->first;
            for(auto str : strs) {
                if (check(str))
                    return str;
            }
        }
        return "";
    }

    bool check(string& str) {
        auto len = str.size();
        while(len > 1) {
            --len;
            str.pop_back();
            if (trie[len].count(str) == 0)
                return false;
        }
        return true;
    }

};