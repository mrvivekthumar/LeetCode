class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), compare);

        int cnt = 1;

        int lastEnd = intervals[0][1];

        for(int i = 1; i < n; i++){
            // Non overlapping
            if(lastEnd <= intervals[i][0]){
                cnt++;
                lastEnd = intervals[i][1];
            }
        }
        return n - cnt;
    }
};