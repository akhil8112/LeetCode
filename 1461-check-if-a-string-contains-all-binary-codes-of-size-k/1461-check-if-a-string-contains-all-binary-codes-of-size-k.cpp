class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n < k) return false;

        int need = 1 << k;          // total patterns
        vector<bool> seen(need, false);

        int mask = 0;
        int all = need - 1;

        for(int i = 0; i < n; i++) {
            mask = ((mask << 1) & all) | (s[i] - '0');

            if(i >= k - 1) {
                if(!seen[mask]) {
                    seen[mask] = true;
                    need--;
                    if(need == 0) return true;
                }
            }
        }
        return false;
    }
};