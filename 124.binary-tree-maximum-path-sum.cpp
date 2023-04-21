/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
/**思路：对于每一个节点进行判断
 * 对于每一个节点来说，若最大路径中包含当前节点，分为两种情况
 * 1. 左+根+右 【使用res来记录所有的这样的情况】
 * 2. 左+根 或 右+根
 * 当时理解误区：
 * 题目中：路径只能经过一次！！所以不能出现以下这种情况
 *         /
 *        /\
 *       /  \ 
 * **/
class Solution {
private:
    int res = -2000;
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        int left_sum = left + root->val;
        int right_sum = right + root->val;
        int sum = left + right + root->val;
        res = max(sum,  res);
        return max(left_sum, right_sum);
    }
};
// @lc code=end

