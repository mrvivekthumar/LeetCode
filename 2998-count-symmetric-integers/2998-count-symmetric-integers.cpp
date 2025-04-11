class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for(int i = low; i <= high; i++){
            if(i >=11 && i <= 99 && (i % 11 == 0)){
                cnt++;
            }else if( i >= 1000 && i <= 9999){
                int firstDigit = (i / 1000);
                int secondDigit = ( i / 100) % 10; 

                int thirdDigit = ( i /10) % 10;   
                int fourthDigit = i % 10;  

                if( firstDigit + secondDigit == thirdDigit + fourthDigit){
                    cnt++;
                } 
            }
        }
        return cnt;
    }
};