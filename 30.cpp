class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int k=0;
        vector<int>ans;
        for(int i=0; i<nums2.size(); i++)
        {
            if(nums2[i]==nums1[0])
                k=i;
                
        }
        int next, i, j;
    for (i=k; i< nums2.size(); i++)
    {
        next = -1;
        for (j = i + 1; j < nums2.size(); j++)
        {
            if (nums2[i] < nums2[j])
            {
                next = nums2[j];
                ans.push_back(next);
                break;
            }
        }
        
    }
        return ans;
    }
};