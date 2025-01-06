class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        map<int,int>mp;
        vector<int>result(n);
        for(int i = 0; i< n; i++){
            if(boxes[i] == '1'){
                mp[i] = 1;
            }
        }

        for(int i = 0; i< n; i++){
            for(auto &[key,value] : mp){
                result[i] += abs(i - key); 
            }
        }

        return result;
    }
};
