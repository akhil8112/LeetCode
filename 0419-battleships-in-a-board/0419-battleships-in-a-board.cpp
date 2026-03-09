class Solution {
public:

    void dfs(vector<vector<char>>& board, int i ,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.'){
            return;
        }
        board[i][j]='.';
        dfs(board,i-1,j,n,m);
        dfs(board,i+1,j,n,m);
        dfs(board,i,j-1,n,m);
        dfs(board,i,j+1,n,m);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
       
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( board[i][j]=='X'){
                    c++;
                    dfs(board,i,j,n,m);
                }
            }
        }
        return c;

    }
};