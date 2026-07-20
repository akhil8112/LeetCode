class Solution {
public:

    int lis(int ind, int prevind, int n, vector<int>nums,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];
        int len=0+lis(ind+1,prevind,n,nums,dp);

        if(prevind==-1 || nums[prevind]<nums[ind]){
            len=max(len,1+lis(ind+1,ind,n,nums,dp));
        }
        dp[ind][prevind+1]=len;
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int len=0+dp[ind+1][prev+1];

                if(prev==-1 || nums[prev]<nums[ind]){
                    len=max(len,1+dp[ind+1][ind+1]);
                }
                dp[ind][prev+1]=len;
            }
        }
        return dp[0][0];
    }
};