class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>pre(n+1,0);
        vector<int>suf(n+2,INT_MAX);
        
        for(int i = 1; i <= n; i++){
             pre[i] = max(pre[i - 1], arr[i - 1]);
        }

        for(int i = n; i >= 1; i--){
            suf[i] = min(suf[i + 1], arr[i - 1]);
        }

        int chunks = 0;
        for(int i =1; i<= n; i++){
            if(pre[i]<=suf[i+1]){
                chunks++;
            }
        }

        return chunks;
    }
};