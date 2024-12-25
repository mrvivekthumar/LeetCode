class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] >= arr[i-1]){
                cnt++;
            }
        }
        if(arr[n-1] <= arr[0]){
            cnt++;
        }

        if(cnt == n || cnt == (n-1)){
            return true;
        }
        return false;
    }
};