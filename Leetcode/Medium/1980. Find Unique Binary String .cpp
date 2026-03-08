// Simple brute force solution
class Solution {
int customAOTIBinary(string n)
{
    int ans = 0;
    for(int i = 0; i< n.length(); i++)
    {
        ans<<=1;
        if(n[i] == '1')
            ans|=1;
    }

    return ans;
}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int maxSize = (1<<nums.size())-1;
        std::unordered_set<int> s;
        for(string n : nums)
            s.insert(customAOTIBinary(n));
        
        while(maxSize > -1)
        {
            if(s.find(maxSize) == s.end())
                return std::bitset<32>(maxSize).to_string().substr(32-nums.size(), nums.size());
            maxSize--;
        }
        
        return "";
    }
};




// awesome solution
// invert each value on index i of string i thus it has at list one index different from every string.

string findDifferentBinaryString(vector<string>& nums)
{
    string ans{};
    ans.reserve(nums.size());
    for(int i = 0; i< nums.size(); i++)
    {
        ans+= nums[i][i] == '0' ? '1' : '0';
    }

    return ans;
}
