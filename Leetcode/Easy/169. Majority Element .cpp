// Time O(n)
// Space O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int val = INT_MIN;
        int count = 1;
        for(int n : nums)
        {
            if(n == val)
                count++;
            else
            {
                count--;
                if(count == 0)
                {
                    val = n;
                    count = 1;
                }
            }
        }

        return val;
    }
};