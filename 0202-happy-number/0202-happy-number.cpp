class Solution {
public:
    int getSquareOutput(int n){
        int sum = 0;
        while(n > 0){
            int reminder = n % 10;
            sum += reminder * reminder;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = getSquareOutput(slow);
            fast = getSquareOutput(getSquareOutput(fast));
        }while(slow != fast);

        return slow == 1;
        
    }
};