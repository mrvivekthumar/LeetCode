class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>>result;

        result.push_back(intervals[0]);

        for(int i = 1; i < n; i++){

            vector<int>& last = result.back();

            if(last[1] > intervals[i][0]){
                last[1] = max(last[1], intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> horizontal;
        vector<vector<int>> verticle;

        for(auto &points  : rectangles){
            int x1 = points[0];
            int y1 = points[1];
            int x2 = points[2];
            int y2 = points[3];
            
            horizontal.push_back({x1,x2});
            verticle.push_back({y1,y2});
        }

        vector<vector<int>> result_1 = merge(horizontal);
        if(result_1.size() >= 3){
            return true;
        }
        vector<vector<int>> result_2 = merge(verticle);

        return result_2.size() >= 3;
    }
};