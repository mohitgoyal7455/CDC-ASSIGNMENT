bool isSafe(vector<vector<char>>& board, int row, int col, int dig){
        for(int j=0;j<9;j++){
            if(board[row][j]==dig){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        }
        int sr = (row/3)*3;
        int sc = (col/3)*3;
        for(int i = sr;i<=sr+2;i++){
            for(int j = sc;j<=sc+2;j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool sudokusolver(vector<vector<char>>& board, int row, int col){
        if(row==9){
            return true;
        }
        int nextrow = row;
        int nextcol = col+1;
        if(nextcol == 9){
            nextrow = row+1;
            nextcol = 0;
        }
        if(board[row][col]!='.'){
            return sudokusolver(board,nextrow,nextcol);
        }
        for(char dig = '1';dig<='9';dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col] = dig;
                if(sudokusolver(board,nextrow,nextcol)){
                    return true;
                }
            }
            board[row][col]='.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokusolver(board,0,0);
    }
