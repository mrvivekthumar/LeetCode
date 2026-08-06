class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>odd(101,0);
        vector<int>even(101,0);
        int n = nums.size();

        // We will use indices as value & value as frequency of that element. 
        // Because the max value of nums[i] is upto 100. 

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                even[nums[i]]++;
            }else{
                odd[nums[i]]++;
            }
        }
        vector<int>result(n);

        int evenLen = even.size();
        int oddLen = odd.size();

        int i = 0; 
        int j = oddLen-1;

        int evenIndex = 0;
        int OddIndex = 1;

        while (i < evenLen ) {
            while(even[i] > 0){
                result[evenIndex] = i;
                evenIndex += 2;
                even[i]--;
            }
            i++;
        }
        while(j > 0){
            while(odd[j] > 0){
                result[OddIndex] = j;
                OddIndex += 2;
                odd[j]--;
            }
            j--;
        }
           
        return result;
    }
};