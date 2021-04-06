#include "util.h"

class Solution {
    // unordered_map<char ,int> setMap;
    set<char> current;
public:
    int lengthOfLongestSubstring(string s) {
        auto first = s.begin();
        auto second = s.begin();
        int result = 0;
        char ch;
        while(first != s.end()){
            while(first!= s.end() && current.count(*first) == 0){
                current.insert(*first);
                // setMap[*first]++;
                ++first;
            }
            
            if(first != s.end()){
                result = max(result, static_cast<int>(first - second));
                auto ch = *first;
                while(*second != ch){
                    current.erase(*second);
                    ++second;
                }
                current.erase(ch);
                ++second;
            }
            else{
                result = max(result, static_cast<int>(first - second));
            }
        }
        return result;
    }
};
