// Time O(n)
// Space O(1)
    vector<int> constructTransformedArray(vector<int>& nums)
    {
        vector<int> o(nums.size());
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                o[i] = 0;
            else if(nums[i]>0)
                o[i] = nums[(i+nums[i])%nums.size()];
            else
            {
                if(nums[i]+i<0)
                    o[i] = nums[(nums.size() - (abs(i+nums[i])%nums.size()))%nums.size()];
                else
                    o[i] = nums[i+nums[i]];
            }
        }

        return o;
    }