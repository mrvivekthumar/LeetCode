class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++){
            v.push_back({nums[i],i});
        }
        vector<bool>visited(n,false);

        sort(v.begin(),v.end());

        long long sum = 0;
        for(auto &it : v){
            int idx =it.second;

            if(!visited[idx]){
                sum += it.first;
                visited[idx] = true;

                if(idx-1 >= 0){
                    visited[idx -1] = true;
                }
                if(idx+1 <n)
                {
                    visited[idx+1] = true;
                }    
            }
                
        }


        return sum;
    }
};