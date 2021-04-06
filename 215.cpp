#include "util.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k - 1);
    }

    int findKthLargest(vector<int>& nums, int left, int right, int k){
        auto mid = partition(nums, left, right);
        if(mid == k){
            return nums[mid];
        }else if(mid < k){   // search in right part
            return findKthLargest(nums, mid + 1, right, k);
        }else{  // search in left part
            return findKthLargest(nums, left, mid - 1, k);
        }
    }

    int partition(vector<int>& nums, int left, int right){
        auto pivot = nums[right];
        auto midIt = std::partition(nums.begin() + left, nums.begin() + right, [pivot](auto val){
            return val > pivot;
        });
        std::iter_swap(midIt, nums.begin() + right);
        return midIt - nums.begin();
    }

};

int main() {
    Solution s;
    vector<int> vec = {3,2,1,5,6,4};
    cout << s.findKthLargest(vec, 2);
}