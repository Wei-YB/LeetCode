#include "util.h"

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                bool up = i > 0;
                bool down = i < (board.size() - 1);
                bool left = j > 0;
                bool right = j < (board[0].size() - 1);
                int cnt = (up && board[i - 1][j] > 0) + 
                          (left && board[i][j - 1] > 0) +
                          (down && board[i + 1][j] > 0) +
                          (right && board[i][j + 1] > 0) + 
                          (up && left && board[i - 1][j - 1] > 0) + 
                          (up && right && board[i - 1][j + 1] > 0) + 
                          (down && left && board[i + 1][j - 1] > 0) + 
                          (down && right && board[i + 1][j + 1] > 0);
                int& cur = board[i][j];
                if(cur == 0){
                    if(cnt == 3)
                        cur = -1;    // -1 is alive
                }
                else if(cnt < 2 || cnt > 3)
                    cur = 2;        // 2 is dead
            }
        }

        for(auto& vec : board){
            for(auto& val : vec){
                if(val == 2)
                    val = 0;
                else if(val == -1)
                    val = 1;
            }
        }

    }
};