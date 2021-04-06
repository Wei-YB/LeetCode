#include "util.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        for(int i = 0; i < height.size() ;++i) {
            while(!stack_.empty() && height[i] > height[stack_.top()]) {
                auto top = stack_.top();
                stack_.pop();
                if(stack_.empty())
                    break;
                const auto left = stack_.top();
                const auto curWidth = i - left - 1;
                const auto curHeight = min(height[left], height[i]) - height[top];
                result += curHeight * curWidth;
            }
            stack_.push(i);
        }
        return result;
    }
private:

    stack<int> stack_;

};