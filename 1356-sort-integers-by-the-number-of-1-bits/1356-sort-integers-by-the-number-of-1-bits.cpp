class Solution {
public:
    int countBits(int x) {
        int cnt = 0;
        while (x > 0) {
            cnt += (x & 1);
            x >>= 1;
        }
        return cnt;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int c1 = countBits(a);
            int c2 = countBits(b);
            
            if (c1 == c2)
                return a < b;
            return c1 < c2;
        });
        
        return arr;
    }
};