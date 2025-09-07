class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        int m = firstList.size();
        int n = secondList.size();

        int first = 0; 
        int second = 0;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        while(first < m && second < n){
            int s1 = firstList[first][0];
            int s2 = secondList[second][0]; 

            int e1 = firstList[first][1];
            int e2 = secondList[second][1];

            // Find intersection 
            int start = max(s1, s2);
            int end = min(e1, e2);

            if(start <= end) {
                result.push_back({start, end});
            }

            // Move the interval with smaller end
            if(e1 < e2) first++;
            else second++;
        }

        return result;
    }
};