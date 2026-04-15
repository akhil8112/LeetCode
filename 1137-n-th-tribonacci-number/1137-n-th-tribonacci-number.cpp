class Solution {
public:
    
    unordered_map<int,int>dp;
    int tib(int n){
        if(n==0 ) return 0;
        else if(n==1 || n==2) return 1;
        if(dp[n]!=0) return dp[n];
        else {
            dp[n-1]=tib(n-1);
            dp[n-2]=tib(n-2);
            dp[n-3]=tib(n-3);
            return dp[n-1]+dp[n-2]+dp[n-3];
        }
    }
    int tribonacci(int n) {
        
        return tib(n);
        
    }
};