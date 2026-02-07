// Time O(n)
// Space O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int cur = 0;
        int lastValue = nums[0]+1;
        int sameCount = 0;
        for(int n : nums)
        {
            if(n == lastValue)
            {
                if(sameCount <2)
                {
                    sameCount++;
                    nums[cur] = n;
                    cur++;
                }
            }
            else
            {
                lastValue = n;
                sameCount = 1;
                nums[cur] = n;
                cur++;
            }
        }

        nums.resize(cur);
        return cur;
    }
};