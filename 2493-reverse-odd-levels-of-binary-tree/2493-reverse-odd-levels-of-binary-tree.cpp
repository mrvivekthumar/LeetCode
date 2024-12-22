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
    void solve(TreeNode* l ,TreeNode* r,int level){
        if(l == nullptr || r == nullptr ){
            return;
        }

        if(level % 2 == 1){
            int temp = l->val;
            l->val = r-> val;
            r->val = temp;
        }

        level++;
        solve(l->left,r->right,level);
        solve(l->right,r->left,level);  

    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left,root->right,1);
        return root;
    }
};