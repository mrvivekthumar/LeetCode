class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int left = 0;
        int right = 0;

        if(n == 1){
            return 1;
        }

        while(right < n){

            int cnt = 0;

            char current = chars[right];

            while(right < n && chars[right] == current){
                cnt++;
                right++;
            }

            chars[left++] = current;

            if(cnt > 1){
                string count = to_string(cnt);
                for(char c : count) {
                    chars[left++] = c;
                }
            }
        }
        chars.resize(left);

        return left;
    }
};