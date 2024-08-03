class Solution {
public:
    int minChanges(int n, int k) {
        long cnt = 0;
        while(n >=1 || k >= 1){
            if(n%2 == 0 && k%2 == 1){
                return -1;
            }
            if(n%2 == 1 && k%2 == 0){
                cnt += 1;
            }
            n = n>>1;
            k = k>>1;
        }
        while( n >=0){
            if(n%2 == 1){
                cnt +=1;
            }
        }

        return cnt;
    }
};