/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = nullptr;
        if(inorder.empty()) return root;
        root = new TreeNode(postorder[postorder.size() - 1]);
        vector<int>::iterator it;
        it = find(inorder.begin(), inorder.end(), root->val);
        int pos = distance(inorder.begin(), it);
        root->left = buildTree(inorder, postorder, postorder.size() - 2, 0, pos - 1);
        root->right = buildTree(inorder, postorder, postorder.size() - 2, pos + 1, inorder.size() - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
    int end_post, int start_in, int end_in){
        TreeNode* root = nullptr;
        if(start_in > end_in || end_post < 0) return root;
        if(start_in ==  end_in){
            root = new TreeNode(inorder[end_in]);
            return root;
        }
        vector<int>::iterator it;
        it = find(inorder.begin() + start_in, inorder.begin() + end_in + 1, postorder[end_post--]);
        while (it == inorder.begin() + end_in + 1)
        {
            it = find(inorder.begin() + start_in, inorder.begin() + end_in + 1, postorder[end_post--]);
        }
        int pos = distance(inorder.begin(), it);
        root = new TreeNode(postorder[end_post + 1]);
        root->left = buildTree(inorder, postorder, end_post, start_in, pos - 1);
        root->right = buildTree(inorder, postorder, end_post, pos + 1, end_in);
        return root;
    }

};
// @lc code=end

