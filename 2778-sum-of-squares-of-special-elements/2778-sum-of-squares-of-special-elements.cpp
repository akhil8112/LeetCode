class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int till = nums.size();
        int ans = 0;

        for (int i = 1; i <= till / 2; i++) {
            if ((till % i) == 0) {
                ans += nums[i - 1] * nums[i - 1];
            }
        }

        ans += nums[till - 1] * nums[till - 1];
        return ans;
    }
};