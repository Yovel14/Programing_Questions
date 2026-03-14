// Brute force not working
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp)
    {
        vector<int> ans(temp.size(),0);
        for(int i = 0; i< temp.size(); i++)
        {
            for(int j = i+1; j< temp.size(); j++)
            {
                cout<< (j-i) <<" ";
                if(temp[j]>temp[i])
                {
                    ans[i] = j-i;
                    break;
                }
            }
            cout<< "\n";
        }
        
        return ans;
    }
};


// Time O(n)
// Space O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp)
    {
        vector<int> ans(temp.size(),0);
        for(int i = temp.size()-2; i > -1; i--)
        {
            int j = i+1;
            while(j< temp.size() && temp[i]>=temp[j])
            {
                if(ans[j] == 0)
                {
                    j = temp.size();
                    break;
                }

                j +=ans[j];
            }
 
            if(j<temp.size())
                ans[i] = j-i;
        }

        return ans;
    }
};