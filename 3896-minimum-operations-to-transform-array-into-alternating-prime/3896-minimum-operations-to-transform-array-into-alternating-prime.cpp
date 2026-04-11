class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int minOperations(vector<int>& nums) {
        
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];

            if (i % 2 == 0) {
                while (!isPrime(val)) {
                    val++;
                    ans++;
                }
            } else {
                while (isPrime(val)) {
                    val++;
                    ans++;
                }
            }
        }

        return ans;
    }
};