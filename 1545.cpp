#include "util.h"

class Solution {
    static int len[21];
    static bool flag;
public:
    char findKthBit(int n, int k) {
        init();
        if (n == 1)
            return '0';
        auto mid = len[n - 1] + 1;
        if (k == mid)
            return '1';
        if (k < mid)
            return findKthBit(n - 1, k);
        if (k > mid)
            return reverse(findKthBit(n - 1, len[n] + 1 - k));
        return '2';
    }

    char reverse(char ch) {
        if (ch == '0')
            return '1';
        return '0';
    }

    static void init() {
        if (flag)
            return;
        len[1] = 1;
        for (int i = 2; i <= 20; ++i) {
            len[i] = 2 * len[i - 1] + 1;
        }
        flag = true;
    }

};

int Solution::len[21];
bool Solution::flag = false;