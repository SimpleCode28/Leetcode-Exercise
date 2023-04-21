/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        if(!root) return v;
        TreeNode* temp = root;
        q.emplace(temp);
        while (!q.empty())
        {
            vector<int> level;
            for(int count = q.size(); count > 0 ; count--){
                temp = q.front();
                q.pop();
                if(temp->left){
                    q.emplace(temp->left);
                }
                if(temp->right){
                    q.emplace(temp->right);
                }
                level.emplace_back(temp->val);
            }
            v.emplace_back(level);
        }
        return v;  
    }
};
// @lc code=end

