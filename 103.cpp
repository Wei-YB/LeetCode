#include "util.h"

class Solution {
    queue<TreeNode*> queue_;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};

        vector<int> temp;
        vector<vector<int>> result;
        
        queue_.push(root);
        TreeNode* leverFlag = root;

        while(!queue_.empty()){
            auto cur = queue_.front();
            queue_.pop();
            temp.push_back(cur->val);
            if(cur->left)
                queue_.push(cur->left);
            if(cur->right)
                queue_.push(cur->right);
            
            if(cur == leverFlag){           // end of level
                leverFlag = queue_.back();
                if(result.size() % 2){       // reverse if current level is in even level
                    reverse(temp.begin(), temp.end());
                }
                result.push_back(temp);
                temp.clear();
            }
        }
        return result;
    }
};