// Time O(nlog(n))
// Space O(n)
class Solution {
  public:
      vector<int> topKFrequent(vector<int>& nums, int k) {
          unordered_map<int,int> m;
          for(int &num: nums)
              m[num]++;
          
          vector<pair<int,int>> v; // <frequency, num>
          v.reserve(m.size());
          for(pair<const int,int> &p : m)
              v.push_back(pair<int,int>(p.second,p.first));
          
          sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){return a.first>b.first;});
  
          vector<int> out;
          out.resize(k);
          for(int i = 0; i<k; i++)
              out[i] = v[i].second;
  
          std::basic_string a;

          return out;
      }
  };