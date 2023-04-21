/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {nullptr};
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int start, int end){
        if(start > end) return {nullptr};
        if(start == end) return {new TreeNode(start)};
        vector<TreeNode*> allTrees;
        for(int i = start ; i <= end ; i++){
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            for(auto& l : left){
                for ( auto& r : right)
                {
                    TreeNode *t = new TreeNode(i, l, r);
                    allTrees.emplace_back(t);
                }
                
            }
        }
        return allTrees;
    }
};
// @lc code=end

