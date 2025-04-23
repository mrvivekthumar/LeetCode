class Solution {
public:
    int findDigitSum(int num){
        int sum = 0;

        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int,int>mp;

        int maxSize = 0;
        int cnt = 0;

        for(int i = 1 ;i <= n; i++){
            int digitSum = findDigitSum(i);

            mp[digitSum]++;

            if(mp[digitSum] == maxSize){
                cnt++;
            }else if ( mp[digitSum] > maxSize){
                maxSize = mp[digitSum];
                cnt = 1;
            }

        }
        return cnt;
    }
};