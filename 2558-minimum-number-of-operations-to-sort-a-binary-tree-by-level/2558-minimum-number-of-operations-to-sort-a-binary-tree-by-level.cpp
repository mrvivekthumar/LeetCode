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
    int coutnSwamps(vector<int> & v){
        int n = v.size();

        int swaps = 0;

        vector<int>sortedVect(v.begin(),v.end());

        sort(sortedVect.begin(),sortedVect.end());

        unordered_map<int,int>mp;

        for(int i = 0; i < n; i++){
            mp[v[i]] = i;
        }

        for(int i = 0; i < n; i++){
            if(v[i] == sortedVect[i]){
                continue;
            }
            
            int currIdx = mp[sortedVect[i]];
            mp[v[i]] = currIdx;
            swap(v[currIdx],v[i]);
            swaps++;
        }

        return swaps;

    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);

        int result = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int>v;
            while(n--){
                TreeNode* ele = q.front();
                q.pop();
                v.push_back(ele->val);

                if(ele->left){
                    q.push(ele->left);
                }
                if(ele->right){
                    q.push(ele->right);
                }

            }
            result += coutnSwamps(v);
        }

        return result;
    }
};