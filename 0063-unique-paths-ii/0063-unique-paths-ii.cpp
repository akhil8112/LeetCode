class Solution {
public:

    int help(vector<vector<int>>& obstacleGrid, int r, int c,  vector<vector<int>>&dp){
        if(r==0 && c==0) return 1;

        if(r<0 || c<0 || r>=obstacleGrid.size() || c>=obstacleGrid[0].size()){
            return 0;
        }

        if(obstacleGrid[r][c]==1) return 0;
        if(dp[r][c]!=-1) return dp[r][c];

        int left=help(obstacleGrid,r-1,c,dp);
        int up=help(obstacleGrid,r,c-1,dp);

        return dp[r][c]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if( obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]) return 0;

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(obstacleGrid,m-1,n-1,dp);
    }
};