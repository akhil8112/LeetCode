class Solution {
public:
    int minOperations(string s) {
         int n = s.size();
        int c0 = 0, c1 = 0;

        for (int i = 0; i < n; i++) {
            char expect0 = (i % 2 == 0) ? '0' : '1'; // pattern "0101..."
            char expect1 = (i % 2 == 0) ? '1' : '0'; // pattern "1010..."
            if (s[i] != expect0) c0++;
            if (s[i] != expect1) c1++;
        }
        return min(c0, c1);
    }
};