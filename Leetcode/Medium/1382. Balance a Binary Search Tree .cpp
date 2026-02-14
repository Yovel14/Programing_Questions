// Time O(n) where n is the number of nodes;
// Space O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
      void buildVector(TreeNode* root, vector<int> &v)
      {
          if(root)
          {
              buildVector(root->right, v);
              v.push_back(root->val);
              buildVector(root->left, v);
          }
      }
  
      TreeNode* recreateTree(vector<int> &v, int s, int e)
      {
          if(s>e)
              return nullptr;
          
          int m = s+(e-s)/2;
          TreeNode *right = recreateTree(v, m+1, e);
          TreeNode *left = recreateTree(v, s, m-1);
          return new TreeNode(v[m], right, left );
          
      }
      TreeNode* balanceBST(TreeNode* root)
      {
          vector<int> v;
          buildVector(root, v);
  
          return recreateTree(v,0,v.size()-1);
      }
  };