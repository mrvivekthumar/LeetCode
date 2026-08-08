class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int productAnswer = nums[0];

        int prefixProduct = 1;
        int suffixProduct = 1;

        for(int i = 0; i < n; i++){

            if(prefixProduct == 0){
                prefixProduct = 1;
            }
            prefixProduct *= nums[i];
            productAnswer = max(productAnswer, prefixProduct);
        }

        for(int i = n-1; i >= 0; i--){

            if(suffixProduct == 0){
                suffixProduct = 1;
            }
            suffixProduct *= nums[i];
            productAnswer = max(productAnswer , suffixProduct);
        }
        return productAnswer;
    }
};