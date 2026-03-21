class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=y;i<y+k;i++){
            int j=x;
            int a=x+k-1;
            while(j<a){
                swap(grid[j][i],grid[a][i]);
                j++;
                a--;
            }
        }
        return grid;
    }
};