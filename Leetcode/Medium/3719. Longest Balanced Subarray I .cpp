// Time O(n^2)
// Space O(n^2)
class Solution {
  public:
      int longestBalanced(vector<int>& nums)
      {
          int maxL = 0;
          unordered_set<int> e;
          unordered_set<int> o;
          for(int j = 0; j< nums.size() && nums.size()-j>maxL; j++) // && nums.size()-j>maxL - optimize for if ending is not longer tha
          {
              e.clear();
              o.clear();
              for(int i = j; i< nums.size() && nums.size()-j>maxL; i++) // && nums.size()-j>maxL - optimize for if ending is not longer tha
              {
                  if(nums[i]&1)
                      o.insert(nums[i]);
                  else
                      e.insert(nums[i]);
                  
                  if(e.size() == o.size())
                      maxL = max(maxL, i-j+1);
              }
          }
  
          return maxL;
      }
  };