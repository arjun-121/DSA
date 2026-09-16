class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> ans(row, vector<int>(col,1));

        int preMul = 1;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j< col; j++) {
                ans[i][j] *= preMul;
                ans[i][j] = ans[i][j] % 12345;
                preMul =  ( 1ll * preMul * grid[i][j]) % 12345;
            }
        }

        int postMul = 1;
        for(int i = row - 1; i>= 0; i--) {
            for(int j = col - 1; j >= 0; j--) {
                ans[i][j] *= postMul;
                ans[i][j] = ans[i][j] % 12345;
                postMul = ( 1ll * postMul * grid[i][j] ) %12345 ;
            }
        } 
        
        return ans;
    }
};