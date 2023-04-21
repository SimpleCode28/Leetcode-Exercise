/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        if(!root) return v;
        if(!root->left && !root->right){
            if(targetSum - root->val == 0){
                vector<int> path;
                path.emplace_back(root->val);
                v.emplace_back(path);
            }
            return v;
        }
        else if(root->left && !root->right){
            vector<int> path;
            path.emplace_back(root->val);
            pathSum(root->left, targetSum - root->val, path, v);
        }
        else if(!root->left && root->right){
            vector<int> path;
            path.emplace_back(root->val);
            pathSum(root->right, targetSum - root->val, path, v);
        }else{
            vector<int> path_l, path_r;
            path_l.emplace_back(root->val);
            path_r.emplace_back(root->val);
            pathSum(root->left, targetSum - root->val, path_l, v);
            pathSum(root->right, targetSum - root->val, path_r, v);
        }
        return v;

    }

    void pathSum(TreeNode* root, int targetSum, vector<int> &path, vector<vector<int>> &v){
        if(!root->left && !root->right){
            if(targetSum - root->val == 0){
                path.emplace_back(root->val);
                v.emplace_back(path);
            }
            return ;
        }
        else if(root->left && !root->right){
            path.emplace_back(root->val);
            pathSum(root->left, targetSum - root->val, path, v);
        }
        else if(!root->left && root->right){
            path.emplace_back(root->val);
            pathSum(root->right, targetSum - root->val, path, v);
        }else{
            vector<int> path_l(path);
            vector<int> path_r(path);
            path_l.emplace_back(root->val);
            path_r.emplace_back(root->val);
            pathSum(root->left, targetSum - root->val, path_l, v);
            pathSum(root->right, targetSum - root->val, path_r, v);
        }
    }
};
// @lc code=end

