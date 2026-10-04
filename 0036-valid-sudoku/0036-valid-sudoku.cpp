class Solution {
public:
    bool traversal(vector<vector<char>>& board, int row, int col){
        map<int,int>mpSudoku;
        for(int i = row; i < row + 3; i++){
            for(int j = col; j < col + 3; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int no = board[i][j] - '0';
                if(mpSudoku[no] == 1){
                    return false;
                }
                mpSudoku[no]++;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        int i = 0;
        while(i < 9){
            map<int,int>mpRow;
            map<int,int>mpCol;

            for(int j = 0; j < 9; j++){
                // for Row
                if(board[i][j] == '.'){
                    continue;
                }
                int no = board[i][j] - '0';

                if(mpRow[no] == 1){
                    return false;
                }
                mpRow[no]++;
            }

            for(int j = 0; j < 9; j++){
                // for Column
                if(board[j][i] == '.'){
                    continue;
                }
                int no = board[j][i] - '0';

                if(mpCol[no]== 1){
                    return false;
                }

                mpCol[no]++;
            }
            i++;
        }

        for(int row = 0; row < 9; row += 3){
            for(int column = 0; column < 9; column += 3){
                if(!traversal(board, row, column)){
                    return false;
                }
            }
        }

        return true;
    }
};