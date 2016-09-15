class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (m + n) & 1 ? findKth(nums1, nums2, (m + n) >> 1):
                             (findKth(nums1, nums2, ((m + n) >> 1) -1) + findKth(nums1, nums2, (m + n ) >> 1)) * .5;
    }
    int findKth(vector<int>& a, vector<int>& b, int kIndex)
    {
        vector<int> c(a.size() + b.size());
        int i = 0, j = 0 , k = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] <= b[j])
                c[k++] = a[i++];
            else
                c[k++] = b[j++];
        }
        while(i < a.size())
            c[k++] = a[i++];
        while(j < b.size())
            c[k++] = b[j++];
        return c[kIndex];
    }
};