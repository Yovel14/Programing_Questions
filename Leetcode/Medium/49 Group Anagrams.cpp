// Time(nmlog(m)) where n is the length of strs and m is the max length of a string in strs
// Space(n*m)
class Solution {
  public:
      vector<vector<string>> groupAnagrams(vector<string>& strs) {
          unordered_map<string,vector<string>> m;
          string temp;
          for(string &s : strs)
          {
              temp = s;
              sort(temp.begin(), temp.end());
              m[temp].push_back(s);
          }
  
          vector<vector<string>> out;
          out.reserve(m.size());
          for(pair<const string, vector<string>> &p : m)
              out.push_back(p.second);
  
          return out;
      }
  };