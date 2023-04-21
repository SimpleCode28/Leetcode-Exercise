/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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

/**
 * 特征：被交换的节点 
 * 两种情况：
 * 1. 被交换的两个数相邻
 * 2. 被交换的两个数不相邻
 * 先中序遍历找到前一个数大于后一个数
 * 可能存在一对，或存在两对
 * **/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* temp = root;
        TreeNode* pre = new TreeNode(-2147483648); 
        TreeNode* r1 = nullptr, *r2 = nullptr;
        while (temp || !s.empty())
        {
            while (temp)
            {
                s.emplace(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            if(pre->val > temp->val){
                if(!r1){
                    r1 = pre;
                    r2 = temp;
                }else{
                    int r = r1->val;
                    r1->val = temp->val;
                    temp->val = r;
                    return ;
                }
            }
            pre = temp;
            temp = temp->right;
        }
        //两个数相邻的情况
        int r = r1->val;
        r1->val = r2->val;
        r2->val = r;
    }
};
// @lc code=end

