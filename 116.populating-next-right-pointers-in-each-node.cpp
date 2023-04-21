/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/**思路：层次遍历,记录前一个节点**/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        Node* temp = root;
        q.emplace(temp);
        bool first = true;
        while (!q.empty())
        {
            Node* pre;
            for(int i = q.size(); i > 0 ; i--){
                temp = q.front();
                q.pop();
                if(first){
                    first = false;
                }else{
                    pre->next = temp;
                }
                pre = temp;
                if(temp->left){
                    q.emplace(temp->left);
                }
                if(temp->right){
                    q.emplace(temp->right);
                }
            }
            first = true;
        }
        return root; 
    }
};
// @lc code=end

