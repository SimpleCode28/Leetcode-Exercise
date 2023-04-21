/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
/**思路：双端队列**/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(!root) return levels;
        deque<TreeNode*> d;
        TreeNode* temp = root;
        d.emplace_front(temp);
        bool order = true;
        while (!d.empty())
        {
            vector<int> level;
            for(int count = d.size(); count > 0 ; count--){
                if(order){
                    //从左边弹出
                    temp = d.front();
                    d.pop_front();
                    if(temp->left) d.emplace_back(temp->left);
                    if(temp->right) d.emplace_back(temp->right);
                }else{
                    temp = d.back();
                    d.pop_back();
                    if(temp->right) d.emplace_front(temp->right);
                    if(temp->left) d.emplace_front(temp->left);
                }
                level.emplace_back(temp->val);
            }
            levels.emplace_back(level);
            order = !order;
        }
        return levels;
    }
};
// @lc code=end

