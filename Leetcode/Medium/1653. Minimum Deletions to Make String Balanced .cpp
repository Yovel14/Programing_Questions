// Time O(n)
// Space O(n)
class Solution {
public:
    int minimumDeletions(string s)
    {
        vector<int> b(s.size(), 0);
        vector<int> a(s.size(), 0);

        int bCount = 0;
        for(int i = 0; i<s.length(); i++)
        {
            b[i] = bCount;
            if(s[i] == 'b')
                bCount++;
        }

        int aCount = 0;
        for(int i = s.length()-1; i>-1; i--)
        {
            a[i] = aCount;
            if(s[i] == 'a')
                aCount++;
        }

        int m = INT_MAX;
        for(int i = 0; i<a.size(); i++)
            m = min(m, a[i]+b[i]);
        
        return m;
    }
};

// Time O(n)
// Space O(n)
class Solution {
public:
    int minimumDeletions(string s)
    {
        int bCount = 0;
        int aCount = 0;
        for(int i = s.length()-1; i>-1; i--)
            if(s[i] == 'a')
                aCount++;

        int m = INT_MAX;
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == 'a')
                aCount--;
            
            m = min(m, aCount+bCount);

            if(s[i] == 'b')
                bCount++;
        }
        
        return m;
    }
};


// Stack
// Time O(n)
// Space O(n)
class Solution {
public:
    int minimumDeletions(string s)
    {
        stack<char> st;
        int dc = 0;
        for(int i = 0; i< s.length(); i++)
        {
            if(!st.empty() && st.top() == 'b' && s[i] == 'a')
            {
                dc++;
                st.pop();
            }
            else
                st.push(s[i]);
        }

        return dc;
    }
};


// DP
// Time O(n)
// Space O(n)
class Solution {
public:
    int minimumDeletions(string s)
    {
        int bCount = 0;
        vector<int> dp(s.length()+1, 0);
        for(int i = 0; i<s.length();i++)
        {
            if(s[i] == 'b')
            {
                dp[i+1] = dp[i];
                bCount++;
            }
            else
                dp[i+1] = min(dp[i] + 1, bCount); 
        }

        return dp[s.length()];
    }
};

// DP
// Time O(n)
// Space O(1)
class Solution {
public:
    int minimumDeletions(string s)
    {
        int bCount = 0;
        int m = 0;
        for(int i = 0; i<s.length();i++)
        {
            if(s[i] == 'b')
                bCount++;
            else
                m = min(m + 1, bCount); 
        }

        return m;
    }
};


// Intuitive Approach for keeping count
// only when you reach an 'a' after a 'b'
// you make a choice remove a or b - it doens't matter which one because they cancel each other out.
// Time O(n)
// Space O(1)
class Solution {
public:
    int minimumDeletions(string s)
    {
        int bCount = 0;
        int d = 0;
        for(char c : s)
        {
            if(c == 'b')
                bCount++;
            else
            {
                if(bCount>0)
                {
                    d++;
                    bCount--;
                }
            }
        }

        return d;
    }
};