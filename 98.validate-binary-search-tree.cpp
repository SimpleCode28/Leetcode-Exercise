/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
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

/**思路：二叉搜索树的中序遍历是一个递增序列
 *所以进行中序遍历的同时进行判断**/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
       if( !root) return true;
       stack<TreeNode*> s;
       TreeNode* temp = root;
       long pre = -2147483650;
       while ( temp || !s.empty())
       {
           while (temp)
           {
               s.push(temp);
               temp = temp->left;
           }
           temp = s.top();
           s.pop();
           if(temp->val <= pre){
               return false;
           }
           pre = temp->val;
           temp = temp->right;
       }
       return true;
       
    }
};
// @lc code=end

