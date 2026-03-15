class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        
        

        for (long long start = 1, digits = 1; start <= n; start *= 10, digits++) {
            long long end = min(n, start * 10 - 1);
            long long count = end - start + 1;

            long long commas = (digits - 1) / 3;

            ans += count * commas;
        }

        return ans;
    }
};