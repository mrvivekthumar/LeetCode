class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings),end(meetings));
        int n = meetings.size();
        int cnt = 0;

        int last_end = 0;

        for(int i = 0; i < n; i++){

            if(meetings[i][0] > last_end + 1){
                cnt += meetings[i][0] - last_end - 1 ;
            }
            last_end = max(last_end, meetings[i][1]);
        }

        if(last_end < days){
            cnt += days - last_end;
        }

        return cnt;
    }
};