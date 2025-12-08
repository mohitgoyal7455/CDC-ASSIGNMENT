class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s = m - 1;
        int k = n - 1;
        int e = m + n - 1;

        while (k >= 0) {
            if (s >= 0 && nums1[s] > nums2[k]) {
                nums1[e] = nums1[s];
                s--;
            } else {
                nums1[e] = nums2[k];
                k--;
            }
            e--;
        }
    }
};