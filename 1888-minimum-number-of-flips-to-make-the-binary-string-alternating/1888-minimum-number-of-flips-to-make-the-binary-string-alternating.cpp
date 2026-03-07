class Solution {
public:
    int minFlips(string s) {
         int n = s.size();
        string t = s + s;

        int diff1 = 0, diff2 = 0;
        int ans = 1e9;

        for (int i = 0; i < 2 * n; i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if (t[i] != expected1) diff1++;
            if (t[i] != expected2) diff2++;

            if (i >= n) {
                char oldExpected1 = ((i - n) % 2 == 0) ? '0' : '1';
                char oldExpected2 = ((i - n) % 2 == 0) ? '1' : '0';

                if (t[i - n] != oldExpected1) diff1--;
                if (t[i - n] != oldExpected2) diff2--;
            }

            if (i >= n - 1) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
        
    }
};