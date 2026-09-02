
class Solution {
public:

    int dfs(int r, int c, int m, int n, vector<vector<int>>& dp) {
         if(r<0 || c<0 || r>=m || c>=n){
            return 0;
        }

        if (r == m - 1 && c == n - 1)
            return 1;

        if (dp[r][c] != -1)
            return dp[r][c];

        int down = dfs(r + 1, c, m, n, dp);
        int right = dfs(r, c + 1, m, n, dp);

       return dp[r][c] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, dp);
    }
};