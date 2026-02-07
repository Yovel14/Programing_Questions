// Time O(n)
// Space O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {// https://github.com/Yovel14/Programing_Questions
        int m = 1;
        int zeroCount = 0;
        for(int n : nums)
            if(n == 0)
            {
                zeroCount++;
                if(zeroCount >1)
                    break;
            }
            else
                m*=n;
        
        if(zeroCount >1)
        {
            vector<int> a(nums.size(), 0);
            return a;
        }    

        vector<int> a;
        a.reserve(nums.size());
        
        for(int n: nums)
        {
            if(zeroCount >0)
            {
                if(n == 0)
                {
                    if(zeroCount == 1)
                        a.push_back(m);
                    else
                        a.push_back(0);
                }
                else
                    a.push_back(0);
            }
            else
                a.push_back(m/n);
        }
        
        return a;
    }
};