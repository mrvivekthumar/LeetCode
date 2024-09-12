class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while ( start > 0 || goal > 0){
            if ((start & 1) != (goal & 1) ){
                cnt++;
            }
            cout<<start<<" :"<<goal<<"      ";
            start = start>>1;
            goal = goal>>1;
        }
        return cnt;
    }
};