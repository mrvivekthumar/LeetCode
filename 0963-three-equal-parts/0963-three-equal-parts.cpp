class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int ones = 0;

        for (int bit : arr) if (bit == 1) ones++;

        if (ones == 0) return {0, n - 1};
        if (ones % 3 != 0) return {-1, -1};

        int k = ones / 3;
        int first = -1, second = -1, third = -1;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                count++;
                if (count == 1) first = i;
                else if (count == k + 1) second = i;
                else if (count == 2 * k + 1) third = i;
            }
        }

        // Compare the sequences starting at first, second, and third
        // in third subarry trailing zero's should be also present in the first and second also otherwise it is not equal.
        while (third < n) {
            if (arr[first] != arr[second] || arr[second] != arr[third])
                return {-1, -1};
            first++;
            second++;
            third++;
        }

        return {first - 1, second};

    }
};