class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>left; // stores left most majority element 
        map<int,int>right; // sotres right most majority element


        int n = nums.size();

        for(auto &num : nums){
            right[num]++;
        }

        for(int i = 0; i < n; i++){
            int currElement = nums[i];

            left[currElement]++;
            right[currElement]--;


            int n1 = i;
            int n2 = n-(i+1);

            // cout<<left[currElement]  << " >" << n1/2 << " " <<right[currElement] << ">" << n2/2<<endl;

            if(left[currElement] > (n1 + 1)/2 && right[currElement] > n2/2){
                return i;
            }
        }

        return -1;
    }
};