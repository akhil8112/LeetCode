class Solution {
public:
    unordered_map<long long,long long>dp;
    int r(long long n ){
        if(n==1) return 0;
        if(dp.find(n)!=dp.end()) return dp[n];
        if(n%2==0){
            dp[n]=1 + r(n/2);
            return dp[n];
           
        }else{
            dp[n]=1+min(r(n+1),r(n-1));
            return dp[n];
            
        } 
    }

    int integerReplacement(int n) {
        
        return r((long long)n);
    }
};