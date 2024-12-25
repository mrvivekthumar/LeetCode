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
    vector<int> largestValues(TreeNode* root) {

        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> vec;

        while(!q.empty()){

            int n = q.size();
            int maxEle = INT_MIN;

            while(n--){

                TreeNode* ele = q.front();
                q.pop();

                maxEle = max(maxEle,ele->val);

                if(ele->left){
                    q.push(ele->left);
                }
                if(ele->right){
                    q.push(ele->right);
                }
            }
            vec.push_back(maxEle);
        }   
        return vec;
    }
};