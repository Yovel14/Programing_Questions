// Time O(n) where n is the number of nodes in the tree
// Space O(h) where h is the depth of the tree

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
  private:
      int isBalancedc(TreeNode* root)
      {
          if(!root)
              return 0;
          
          int l = isBalancedc(root->left);
          if(l == -1)
              return -1;
          int r = isBalancedc(root->right);
          if(r == -1 || abs(r-l)>1)
              return -1;
  
          return max(l,r)+1;
      }
  public:
      bool isBalanced(TreeNode* root)
      {
          return isBalancedc(root) != -1;
      }
  };


// Stack
// Time O(n) where n is the number of nodes in the tree
// Space O(h) where h is the depth of the tree

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
  private:
      struct RecursionStuck// the Same as TreeNode But Different Usage
      {
          int state = 0; // 0 - not processed yet, 1 - processed left, 2 - processed right
          TreeNode *node;
          int left;
          int right;
          RecursionStuck() : state(0),node(nullptr), left(0), right(0)  {}
          RecursionStuck(int x = 0) : state(x),node(nullptr), left(0), right(0) {}
          RecursionStuck(int x = 0, TreeNode *node = nullptr , int left = 0, int right = 0) : state(x), node(node), left(left), right(right) {}
      };
  public:
      bool isBalanced(TreeNode* root)
      {
          stack<RecursionStuck*> st;
          st.push(new RecursionStuck(0,root));
  
          while(!st.empty())
          {
              RecursionStuck *cur = st.top();
              if(!cur->node || cur->state == 2)
              {
                  if(abs(cur->left-cur->right)>1) // stop condition
                      return false;
                  st.pop();
                  if (!st.empty())
                  {   
                      if(st.top()->state == 0)
                      {
                          st.top()->left+=max(cur->left,cur->right)+1;// return value
                          st.top()->state++;
                      }
                      else if(st.top()->state == 1)
                      {
                          st.top()->right+=max(cur->left,cur->right)+1;
                          st.top()->state++;
                      }
                  }
              }
              else if (cur->state == 1)
                  st.push(new RecursionStuck(0,cur->node->right));
              else // cur->state == 0
                  st.push(new RecursionStuck(0,cur->node->left));
          }
  
          return true;
      }
  };