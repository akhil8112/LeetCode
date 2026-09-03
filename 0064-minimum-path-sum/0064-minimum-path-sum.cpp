class Solution {
public:

    int help(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j<0 ){
            return 1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int up = grid[i][j]+ help(grid,i-1,j,dp);
        int left = grid[i][j]+help(grid,i,j-1,dp);

        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }

                int up =1e9;
                if(i>0)
                    up=grid[i][j]+ dp[i-1][j];

                int left = 1e9;
                if(j>0)
                    left=grid[i][j]+dp[i][j-1];

                dp[i][j]=min(up,left);
            }
        }
        return dp[m-1][n-1]; 
    }
};