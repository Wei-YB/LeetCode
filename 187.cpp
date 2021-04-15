#include "util.h"

class Solution {
    // unordered_map<string, int> words;
    unordered_map<string_view, int> words;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10)
            return {};
        auto end = s.end() - 9;
        for (auto it = s.begin(); it != end; ++it) {
            ++words[string_view(&*it, 10)];
        }

        vector<string> result;

        for (auto& p : words) {
            if (p.second > 1) {
                result.emplace_back(string(p.first));
            }
        }

        return result;
    }
};


int main() {
    Solution s;
    auto result = s.findRepeatedDnaSequences("AAAAAAAAAAA");
    test::print_vector(result);
}