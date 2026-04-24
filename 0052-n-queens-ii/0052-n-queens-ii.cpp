class Solution {
public:
   bool isSafe(int row,int col,vector<vector<string>>&ans,  vector<string>&board, int n){

        //check row
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }

        //check col
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q') return false;
        }

        //left diaognal
        for(int i=row,j=col;i>=0 && j>=0 ; i--,j--){
            if(board[i][j]=='Q') return false;
        }

        //right dioagnal
        for(int i=row,j=col;i>=0 && j<n ; i--,j++){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }
    void solve(int row, vector<vector<string>>&ans,  vector<string>&board, int n ){
        if(row==n){
            ans.push_back({board});
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(row,col,ans,board,n)){
                board[row][col]='Q';
                solve(row+1,ans,board, n);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
         vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));

        solve(0,ans,board,n);

        return ans.size();
    }
};