class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>ans(r,vector<int>(c));
        int n=mat.size();
        int m=mat[0].size();
        
        if(m*n!=r*c) return mat;

        int cu=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[cu/c][cu%c]=mat[i][j];
                cu++;
            }
        }
        return ans;

    }
};