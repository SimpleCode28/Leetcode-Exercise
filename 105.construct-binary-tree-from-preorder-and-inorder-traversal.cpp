/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        if(preorder.empty()) return root;
        //根节点位置
        root = new TreeNode(preorder[0]);
        int temp = preorder[0];
        //查找根节点在inorder中的位置
        vector<int>::iterator it;
        it = find(inorder.begin(), inorder.end(), temp);
        int pos = distance(inorder.begin(), it);
        //构建根节点的左右子树
        root->left = buildTree(preorder, inorder, 1, 0, pos - 1);
        root->right = buildTree(preorder, inorder,1, pos + 1, inorder.size() - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, 
    int start_pre, int start_in, int end_in){
        TreeNode* root = nullptr;
        if(start_in > end_in) return root;
        if(start_in == end_in) {
            root = new TreeNode(inorder[end_in]);
            return root;
        }
        //找到根的位置
        vector<int>::iterator it;
        // 迭代器的加减n：向后（前）移动n个位置，使用find进行查找时，左闭右开，
        // 像inorder.end()指向的是数组最后一个位置的下一个位置
        it = find(inorder.begin() + start_in, inorder.begin() + end_in + 1, preorder[start_pre++]);
        while (it == inorder.begin() + end_in + 1)
        {
            it = find(inorder.begin()+ start_in , inorder.begin() + end_in + 1, preorder[start_pre++]);
        }
        int pos = distance(inorder.begin(), it);
        //建立根节点
        root = new TreeNode(preorder[start_pre - 1]);
        root->left = buildTree(preorder, inorder, start_pre, start_in, pos - 1);
        root->right = buildTree(preorder, inorder, start_pre, pos + 1, end_in);
        return root;
    }
};
// @lc code=end

