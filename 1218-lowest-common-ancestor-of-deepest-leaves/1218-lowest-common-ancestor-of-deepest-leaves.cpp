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
    unordered_map<int,int> mp;
    int maxDepth = 0;

    TreeNode * LCA(TreeNode* root){
        if(root == NULL || mp[root->val] == maxDepth){
            return root;
        }

        TreeNode *left = LCA(root->left);
        TreeNode *right = LCA(root->right);

        if(left && right){
            return root;
        }

        return left != NULL ? left : right;
     }
    
    void traverse(TreeNode* root , int depth){

        if(!root){
            return;
        }

        maxDepth = max(maxDepth , depth);
        mp[root->val] = depth;

        traverse(root->left , depth +1);
        traverse(root->right , depth +1);
    } 


    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        traverse(root,0);

        return LCA(root);
    }
};