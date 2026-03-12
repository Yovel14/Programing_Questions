// Time Limit
// Time O(n*n*m) where n is size of nums, m max number size
// Space O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int maxLen = 0;
        for(int startingNumberIndex = 0; startingNumberIndex< nums.size();startingNumberIndex++)
        {
            int curLen = 1;
            int currentNum = nums[startingNumberIndex];
            bool foundNext = true;
            while(foundNext)
            {
                foundNext = false;
                for(int n : nums)
                {
                    if(n== currentNum+1)
                    {
                        foundNext = true;
                        curLen++;
                        currentNum++;
                        break;
                    }
                }
            }
            maxLen = max(maxLen, curLen);
        }

        return maxLen;
    }
};


// Time O(n)
// Space O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int curLen = 1;

        for(int i = 1; i< nums.size(); i++)
        {
            if(nums[i]== nums[i-1]+1)
            {
                curLen++;
                maxLen = max(maxLen, curLen);
            }
            else if(nums[i] != nums[i-1])
                curLen = 1;
        }

        return maxLen;
    }
};



// Time
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;

        unordered_map<int, bool> m;
        for(int n : nums)
            m[n] = true;
        
        for(int n : nums)
            if(m.find(n-1) != m.end())
                m[n] = false;
        
        int maxLen = 0;
        for(int n : nums)
        {
            if(m[n])
            {
                int curLen = 1;
                int curNum = n+1;
                while(m.find(curNum) != m.end())
                {
                    curLen++;
                    curNum++;
                }

                maxLen = max(maxLen, curLen);
                m[n] = false;
            }
        }

        return maxLen;
    }
};


// failes because of duplicate numbers

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;

        unordered_set<int> s;
        for(int n : nums)
            s.insert(n);

        int maxLen = 0;
        for(int n : nums)
        {
            if(s.find(n-1) == s.end())
            {
                int curLen = 1;
                int curNum = n+1;
                while(s.find(curNum) != s.end())
                {
                    curLen++;
                    curNum++;
                }

                maxLen = max(maxLen, curLen);
            }
        }

        return maxLen;
    }
};