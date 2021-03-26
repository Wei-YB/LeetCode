#include "util.h"


class Solution {
public:
    int myAtoi(string s) {
        int index = 0;

        // ignore the space
        while (s[index] == ' ')
            ++index;

        // flag check
        bool negaive = false;
        if (s[index] == '-') {
            negaive = true;
            ++index;
        }
        else if (s[index] == '+') {
            ++index;
        }

        int val = 0;
        while (index < s.size() && isdigit(s[index])) {
            if (willOverflow(val, s[index], negaive)) {
                return negaive ? INT_MIN : INT_MAX;
            }
            else {
                int digit = negaive ? -(s[index] - '0') : s[index] - '0';
                val = val * 10 + digit;
                ++index;
            }
        }
        return val;
    }

    bool willOverflow(int val, char next, bool flag) {
        int digit = next - '0';
        if(flag)
            digit = -digit;
        if(flag) {
            return  val < (INT_MIN - digit) / 10;
        }else {
            return (INT_MAX - digit) / 10 < val;
        }
    }

};


int main() {
    Solution s;
    cout <<s.myAtoi("-1234")<<endl;
}