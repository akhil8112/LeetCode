class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int r=king[0];
        int c=king[1];
        vector<vector<int>>board(8,vector<int>(8,0));

        for(int i=0;i<queens.size();i++){
            int a=queens[i][0];
            int b=queens[i][1];

            board[a][b]=1;
        }
       
        //right , left, up , down, upper left, upper right, lower left, lower right

        int dx[]={0,0,-1,1,-1,-1,1,1};
        int dy[]={1,-1,0,0,-1,1,-1,1};

        vector<vector<int>>ans;

        for(int i=0;i<8;i++){
            int nr=r;
            int nc=c;
            for(int j=0;j<8;j++){
                nr=nr+dx[i];
                nc=nc+dy[i];
                if(nr>=0 && nr<8 && nc>=0 && nc<8){
                    if(board[nr][nc]==1){
                        ans.push_back({nr,nc});
                        break;
                    }
                }
            }
        }

        return ans;
    }
};