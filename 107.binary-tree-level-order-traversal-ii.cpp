/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levels;
        if(!root) return levels;
        queue<TreeNode*> q;
        TreeNode* temp = root;
        q.emplace(temp);
        while (!q.empty())
        {
            vector<int> level;
            for(int i = q.size(); i > 0 ; i--){
                temp = q.front();
                q.pop();
                level.emplace_back(temp->val);
                if(temp->left) q.emplace(temp->left);
                if(temp->right) q.emplace(temp->right);
            }
            levels.emplace_back(level);
        }
        reverse(levels.begin(), levels.end());
        return levels;
    }
};
// @lc code=end

