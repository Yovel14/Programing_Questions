// Time O(n)
// Space O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int cur = 0;
        for(int n : nums)
        {
            if(n!=val)
                nums[cur++] = n;
        }

        return cur;
    }
};