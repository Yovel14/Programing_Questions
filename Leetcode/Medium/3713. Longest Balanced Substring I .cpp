// Time O(n^2)
// Space O(n^2)
class Solution {
  public:
      int longestBalanced(string &s)
      {
          int maxL = 0;
          for(int i = 0; i< s.length() && s.length()-i>maxL; i++)
          {
              int maxc = 0;
              int  m[26] = {0};
              for(int j = i; j<s.length() && s.length()-i>maxL; j++)
              {
                  m[s[j]-'a']++;
                  if(j-i+1>maxL)
                  {
                      bool same = true;
                      int lastValue = 0;
                      for(int n : m)
                      {
                          if(n!=0)
                          {
                              if(lastValue == 0)
                                  lastValue = n;
                              else
                                  if(n!=lastValue)
                                  {
                                      same = false;
                                      break;
                                  }
                          }
                      }
  
                      if(same)
                          maxL = max(maxL, j-i+1);
                  }
              }
          }
  
          return maxL;
      }
  };