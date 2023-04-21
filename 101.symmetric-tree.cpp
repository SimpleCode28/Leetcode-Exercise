/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
/**思路：递归**/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if( !root->left && !root->right) return true;
        if(!(root->left && root->right)) return false;
        return isSameReverse(root->left, root->right);
        
    }

    bool isSameReverse(TreeNode* p, TreeNode* q){
        if( !p && !q) return true; //同时为nullptr
        if( !(p && q)) return false; //一个为null另一个不为null
        if(p->val !=  q->val) return false; //都不为null 但值不相同
        return (isSameReverse(p->left, q->right) && isSameReverse(p->right, q->left));
    }
};
// @lc code=end

