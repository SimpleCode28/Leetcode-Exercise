/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
class Solution {
    private: int ans = 0;
public:
    int sumNumbers(TreeNode* root) {
        if(!root->left && !root->right){
            return root->val;
        }
        if(root->left) getNumber(root->left, root->val);
        if(root->right) getNumber(root->right, root->val);

        return ans;
    }

    void getNumber(TreeNode* root, int pre){
        int temp = pre * 10 + root->val;
        if(!root->left && !root->right){
            ans = ans + temp;
            return;
        }
        if(root->left) getNumber(root->left, temp);
        if(root->right) getNumber(root->right, temp);
    }
};
// @lc code=end

