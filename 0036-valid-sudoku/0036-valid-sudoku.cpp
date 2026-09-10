class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row, int col, char num) {
        for(int k = 0; k < 9; k++) {
            if(board[row][k] == num && k != col) {
                cout << " Inside row if statement " << board[row][k] << "\n";
                    return false;
            }
        }
        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int row, int col, char num) {
        for(int k = 0; k < 9; k++) {
            if(board[k][col] == num && k != row) {
                cout << " Inside Col if statement " << board[k][col] << "\n";
                    return false;
            }
            
        }
        return true;
    }

    bool isValidMatrix(vector<vector<char>>& board, int row, int col, char num) {
        cout << " Matrix " << row << " " << col << " " << num << " \n";
        int rowQuo = row / 3;
        int colQuo = col / 3;
        int mRowStart = rowQuo * 3;
        int mRowEnd = rowQuo * 3 + 3;
        int mColStart = colQuo * 3;
        int mColEnd = colQuo * 3 + 3;

        for(int k = mRowStart; k < mRowEnd; k++) {
            for(int l = mColStart; l < mColEnd; l++) {
                if(board[k][l] == num && k != row && l != col)
                    {
                        cout << " Inside matrix if statement " << board[k][l] << "\n";
                        return false;
                    }
            }
            
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        for( int i = 0; i < rows; i++) {
            for (int j = 0; j< cols; j++) {
                if( board[i][j] != '.') {
                    bool validMat = isValidMatrix(board, i, j, board[i][j]);
                    bool validCol = isValidCol(board,i, j, board[i][j]);
                    bool validRow = isValidRow(board, i, j, board[i][j]);
                    
                    cout << i << j << validMat << validRow << validCol << "\n";

                    if(!validMat || !validRow || !validCol) {
                        return false;
                    }
                }
            }
        }
        return true;        
    }
};