class Solution {
public:
    int t[366];
    int solve(vector<int>& days, vector<int>& costs, int n, int idx){
        // base condition
        if(idx >= n){
            return 0;
        }
        // check if already cheked or not 
        if(t[idx] != -1){
            return t[idx];
        }

        // 1 day pass
        int cost1 = costs[0] + solve(days , costs , n , idx+1);

        // 2 day pass
        int j = idx;
        int pass2LastDay = days[idx] + 7; 
        while( j < n && days[j] < pass2LastDay){
            j++;
        }
        int cost2 = costs[1] + solve(days , costs, n, j);

        // 3 day pass
        int k = idx;
        int pass3LastDay = days[idx] + 30;
        while(k < n && days[k] < pass3LastDay){
            k++;
        }
        int cost3 = costs[2] + solve(days, costs,n, k);

        int ans = min(min(cost1,cost2),cost3);

        return t[idx] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(t, -1 , sizeof(t));
        return solve(days,costs,n, 0);

    }
};