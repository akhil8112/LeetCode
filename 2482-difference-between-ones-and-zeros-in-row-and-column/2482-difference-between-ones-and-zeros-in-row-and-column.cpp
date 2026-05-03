class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int>rz(m,0);
        vector<int>cz(n,0);
        vector<int>ro(m,0);
        vector<int>co(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    rz[i]++;
                    cz[j]++;
                }else{
                    ro[i]++;
                    co[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=ro[i]+co[j]-rz[i]-cz[j];
            }
        }
        return grid;

    }
};