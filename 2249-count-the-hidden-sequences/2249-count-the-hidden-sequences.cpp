class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int current = 0; // a[0] hidden sequence
        int minValue = 0;
        int maxValue = 0;

        for(int &d : differences){
            current += d;

            minValue = min(minValue , current);
            maxValue = max(maxValue , current);

            if((upper-maxValue) - (lower-minValue) + 1 <= 0){
                return 0;
            }
        }  

        return  (upper-maxValue) - (lower-minValue) + 1;
    }
};