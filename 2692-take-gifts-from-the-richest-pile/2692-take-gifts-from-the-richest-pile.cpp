class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int>q(gifts.begin(), gifts.end());

        int n = gifts.size(); 

        int start = n - k;

        for(int i = start; i < n ; i++){
            int top = q.top();
            q.pop();
            q.push(floor(sqrt(top)));
        }

        long long sum = 0;

        while(!q.empty()){
            sum+=q.top();
            q.pop();
        }
        return sum;
    }
};