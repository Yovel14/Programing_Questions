// Time O(n)
// Space O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) { // https://github.com/Yovel14/Programing_Questions
        int i = 0;
        int progress = 0;
        while(i<nums.size()-1 && nums[i]<nums[i+1])
            i++;
        
        if(i == progress || i == nums.size()-1)
            return false;
        progress = i;
        while(i<nums.size()-1 && nums[i]>nums[i+1])
            i++;

        if(i == progress ||i == nums.size()-1)
            return false;
        progress = i;
        while(i<nums.size()-1 && nums[i]<nums[i+1])
            i++;

        return i != progress  &&i == nums.size()-1;
}
};