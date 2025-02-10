class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int > ballmp; //{ ball , color}
        unordered_map<int, int > colormp; // { color , count}
        vector<int> result;

        int n = queries.size();

        for(int i = 0; i < n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballmp.find(ball) != ballmp.end()){
                int prevBallColor = ballmp[ball];
                colormp[prevBallColor]--;

                if(colormp[prevBallColor] == 0 ){
                    colormp.erase(prevBallColor);
                }
            }
            
            ballmp[ball] = color;
            colormp[color]++;

            result.push_back(colormp.size());
        }

        return result;
    }
};