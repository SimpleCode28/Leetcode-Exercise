/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        if(nums.empty()) return root;
        int pos = ceil((nums.size() - 1)/2); //向下取整
        cout << pos << endl;
        root = new TreeNode(nums[pos]);
        root->left = sortedArrayToBST(nums, 0, pos - 1);
        root->right = sortedArrayToBST(nums, pos + 1, nums.size() - 1);
        return root;
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        TreeNode * root = nullptr;
        if(start > end) return root;
        if(start == end){
            root = new TreeNode(nums[start]);
            return root;
        }
        int pos = (end + start)/2;
        root = new TreeNode(nums[pos]);
        root->left = sortedArrayToBST(nums, start, pos - 1);
        root->right = sortedArrayToBST(nums, pos + 1, end);
        return root;
    }

};
// @lc code=end

