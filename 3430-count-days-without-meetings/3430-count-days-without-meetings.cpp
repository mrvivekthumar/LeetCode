class Solution {
public:
    // USING STL METHOD  
    //  WORKS ONLY IN SMALL TEST CASES IT GIVES TLE IN THIS TYPE OF BIG CONSTRAINTS 
    // int countDays(int days, vector<vector<int>>& meetings) {
    //     vector<bool> available(days + 1, true); 

    //     for (auto& meeting : meetings) {
    //         fill(available.begin() + meeting[0], available.begin() + meeting[1] + 1, false);
    //     }

    //     return count(available.begin() + 1, available.end(), true);
    // }



    // GOOD APPROACH ACCORDING TO MATH WISE 
    
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