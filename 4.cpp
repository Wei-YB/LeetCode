#include "util.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const auto length = nums1.size() + nums2.size();
        if (length % 2) {
            return static_cast<double>(
                findKth(nums1, nums2, (length + 1) / 2));
        }
        else {
            return
                static_cast<double>
                (
                    findKth(nums1, nums2, length / 2) +
                    findKth(nums1, nums2, length / 2 + 1)
                )
                / 2;
        }
    }

    int findKth(const vector<int>& nums1, const vector<int>& nums2, int k) {
        const int size1 = nums1.size();
        const int size2 = nums2.size();
        int index1 = 0, index2 = 0;

        while(true) {
            if(index1 == size1) {       // first went end, find kth of right
                return nums2[index2 + k - 1];
            }if(index2 == size2) {      // same as second went end
                return nums1[index1 + k - 1];
            }
            if(k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            int newIndex1 = min(index1 + k / 2 - 1, size1 - 1);
            int newIndex2 = min(index2 + k / 2 - 1, size2 - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }

        }
    }
};


int main() {
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}
