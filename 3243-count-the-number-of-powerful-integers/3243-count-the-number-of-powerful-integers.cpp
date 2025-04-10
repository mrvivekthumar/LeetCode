class Solution {
public:
    long long powInt(int base, int exp) {
        long long res = 1;
        while (exp--) res *= base;
        return res;
    }

    long long solve(string &str, string &suffix, int limit) {
        if (str.length() < suffix.length()) return 0;

        // Check if suffix is valid (each digit <= limit)
        for (char ch : suffix) {
            if ((ch - '0') > limit) return 0;
        }

        long long cnt = 0;
        string prefix = str.substr(0, str.length() - suffix.length());
        int length = prefix.length();

        for (int i = 0; i < length; ++i) {
            int digit = prefix[i] - '0';

            for (int d = 0; d < digit; ++d) {
                if (d > limit) continue;
                cnt += powInt(limit + 1, length - i - 1);
            }

            if (digit > limit) return cnt;
        }

        if (prefix + suffix <= str) {
            cnt += 1;
        }

        return cnt;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start - 1);
        string endStr = to_string(finish);
        return solve(endStr, s, limit) - solve(startStr, s, limit);
    }
};
