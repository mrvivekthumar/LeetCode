class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double,int>>pq;

        for(int i = 0; i <n; i++){
            double pr = (double) classes[i][0] / classes[i][1];
            double new_pr = (double) (classes[i][0] + 1) / (classes[i][1] + 1);
            double delta = new_pr - pr;
            pq.push({delta, i});
        }

        while(extraStudents--){
            auto it = pq.top();
            pq.pop();

            int idx = it.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double current_PR =(double) classes[idx][0] / classes[idx][1];
            double new_PR = (double) (classes[idx][0]+ 1 )/ (classes[idx][1] + 1);
            
            double new_delta = new_PR - current_PR;

            pq.push({new_delta , idx});
        }

        double result = 0.0;
        for(int i = 0; i < n; i++){
            result += (double) classes[i][0] /classes[i][1];
        }

        return result/n;
    }
};