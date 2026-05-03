class Solution {
public:
    bool safe(vector<vector<char>>& board,int r,int co,char c){
        //row
        for(int i=0;i<9;i++){
            if(board[r][i]==c) return false;
        }
        //col
        for(int i=0;i<9;i++){
            if(board[i][co]==c) return false;
        }
        //3*3 box
        for(int i=0;i<9;i++){
            if (board[3 * (r / 3) + i / 3][3 * (co / 3) + i % 3] == c) return false;
        }

        return true;

    }
    bool sudoku(vector<vector<char>>& board){
        
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                        for(int i=0;i<9;i++){
                            char c='1'+i;
                            if(safe(board,row,col,c)){
                                board[row][col]=c;
                                if(sudoku(board))return true;
                                board[row][col]='.';
                            }

                        }
                        return false;
                } 
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
};