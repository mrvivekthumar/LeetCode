class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>count(26, 0);

        for ( auto &ch : s){
            count[ch-'a']++;
        }

        priority_queue<char>pq;

        for(int i =0; i < 26; i++){
            if(count[i] > 0){
                char ch = 'a' + i;
                pq.push(ch);
            }
        }

        string result;
        while(!pq.empty()){
            char ch = pq.top();
            pq.pop();
            
            int freq = min(repeatLimit,count[ch-'a']);
            result.append(freq,ch);

            count[ch-'a'] -= freq;

            if(count[ch-'a'] > 0 && !pq.empty()){
                int newCh = pq.top();
                pq.pop();

                result.push_back(newCh);

                count[newCh-'a']--;

                if(count[newCh - 'a'] > 0){
                    pq.push(newCh);
                }
                pq.push(ch);
            }
        }
        return result;
    }
};