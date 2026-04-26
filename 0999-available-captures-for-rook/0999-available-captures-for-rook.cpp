class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r;
        int c;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    r=i;
                    c=j;
                    break;
                }
            }
        }

        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        int attack=0;

        for(int i=0;i<4;i++){
            int nr=r;
            int nc=c;
            for(int j=0;j<8;j++){
                nr=nr+dx[i];
                nc=nc+dy[i];
                if(nr>=0 && nc>=0 && nr<8 && nc<8){
                    if(board[nr][nc]=='B'){
                        break;
                    }else if(board[nr][nc]=='p'){
                        attack++;
                        break;
                    }

                }
            }
        }

        return attack;
    }
};