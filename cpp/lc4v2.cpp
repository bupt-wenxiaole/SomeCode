//O(lg(m+n))
class Solution
{
public:
    int findk(int *a, int *b, int lena, int lenb, int k)
    {
        if(lena > lenb)
            return findk(b, a, lenb, lena, k);
    
        if(lena == 0)
            return b[k-1];
        if(k==1)
            return min(a[0],b[0]);
        int pa = min(k >> 1,lena), pb = k - pa;
        return (a[pa - 1] < b[pb - 1])? findk(a+pa,b,lena-pa,pb, k -pa) : findk(a, b+pb, pa, lenb-pb, k-pb);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int *a = new int[m];
        for(int i = 0; i < m; i++)
            a[i] = nums1[i];
        int *b = new int[n];
        for(int i = 0; i < n; i++)
            b[i] = nums2[i];
        return ((m + n) & 1) ? findk(a,b,m,n,(m+n+1)>>1):
        (findk(a, b, m, n, (m + n) >> 1) + findk(a,b,m,n,((m+n)>>1)+1)) * .5;
    }
};
