class Solution {
public:
    bool allzero(int row,int col,vector<vector<int>>& mat ){
        for(int i=0;i<mat[0].size();i++){
            if(mat[row][i]==1 && i!=col){
                return false;
            }
        }
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]==1 && i!=row){
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int c=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1 && allzero(i,j,mat)){
                    c++;
                }
            }
        }
        return c;
    }
};