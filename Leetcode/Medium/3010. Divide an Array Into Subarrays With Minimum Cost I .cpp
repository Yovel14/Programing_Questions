// Time O(n)
// Space O(1)
class Solution {
  public:
      int minimumCost(vector<int>& nums)
      {
          vector<int> min {INT_MAX, INT_MAX};
          for(int x = 1; x< nums.size(); x++)
          {
              int n = nums[x];
              int i = 0;
              while(i<min.size() && n<min[i])
                  i++;
  
              i--;
              for(int j = 0; j<i;j++)
                  min[j] = min[j+1];
              if(i>-1)
                  min[i] = n;
          }
          int sum = nums[0];
          for(int n: min)
              sum+=n;
          return sum;
      }
  };