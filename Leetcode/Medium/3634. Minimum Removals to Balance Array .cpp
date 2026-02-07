// Time O(nlog(n))
// Space O(1)

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) 
    { // https://github.com/Yovel14/Programing_Questions
        // balance if min(nums)*k >= max(nums)
        int maxSize = 1;
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = 0;
        while(s<nums.size() && e+1 < nums.size())
        {
            if(nums[e+1] > ((long)nums[s])*k)
            
                s++;
            else
                e++;
            maxSize = max(maxSize, e-s+1);
        }

        return nums.size()-maxSize;
    }
};