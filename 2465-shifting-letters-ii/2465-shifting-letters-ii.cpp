class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.size();

        vector<int>v(len, 0);

        int m = shifts.size();
        
        for(int i = 0; i < m; i++){

            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];

            int value;

            if(dir == 0){
                value = -1;
            }else{
                value = 1;
            }

            v[start] += value;

            if(end+1 < len){                    
                v[end+1] -= value; 
            }
        }

        //  Cumullative sum for change the total character by this value.
        for(int i = 1; i < len; i++){
            v[i] += v[i-1];
        }


        for(int i = 0; i < len; i++){

            int shift = v[i] % 26;

            if(shift < 0){
                shift += 26;
            }

            // for differenc of int to char transformation 
            int currentCharPosition = s[i] - 'a';
            int newCharPosition = (currentCharPosition + shift)  % 26; 
            char newChar = newCharPosition + 'a';
            s[i] = newChar;
        }

        return s;
    }
};