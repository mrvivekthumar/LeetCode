class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int>res;
        map<int,int>mp; //   value -> index
        int n = nums.size();

        for(int i = 0; i< n; i++){
            
            int remSum = target - nums[i];

            if(mp.find(remSum) != mp.end()){
                res.push_back(i);
                res.push_back(mp[remSum]);

            }
            mp[nums[i]] = i;
        }

        return res;
        // BRUTE FORCE

        // vector<int> v;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             v.push_back(i);
        //             v.push_back(j);
        //             break;
        //             break;
        //         }
        //     }
        // }
        // return v;
    }
};