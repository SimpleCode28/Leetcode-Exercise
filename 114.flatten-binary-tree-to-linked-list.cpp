/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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

/**思路：先序遍历**/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        stack<TreeNode*> s;
        TreeNode* res = new TreeNode(root->val);
        TreeNode* temp = res;
        TreeNode* t = root;
        s.emplace(t);
        t = t->left;
        while (t || !s.empty())
        {
            while(t){
                res->right = new TreeNode(t->val);
                res =res->right;
                s.emplace(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            t = t->right;
        }
        root->left = nullptr;
        root->right = temp->right;
    }
};
// @lc code=end

