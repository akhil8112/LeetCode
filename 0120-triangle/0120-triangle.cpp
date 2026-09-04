class Solution {
public:
    int help(vector<vector<int>>& triangle, int r, int c,  vector<vector<int>>& dp){
        if(r==triangle.size()-1 || c==triangle[r].size()-1) return triangle[r][c];

        if(dp[r][c]!=-1) return dp[r][c];

        int take=triangle[r][c] + help(triangle,r+1,c,dp);
        int skip=triangle[r][c] + help(triangle,r+1,c+1,dp);

        return dp[r][c]=min(take,skip);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {

                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diag);
            }
        }


        return dp[0][0];
    }
};