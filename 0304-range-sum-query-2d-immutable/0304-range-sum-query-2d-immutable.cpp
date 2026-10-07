class NumMatrix {
public:
    vector<vector<int>> prefixSumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        // Row Wise Prefix Matrix;
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        // Column wise prefix Matrix 
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] += matrix[i-1][j]; 
            }
        }

        prefixSumMatrix = matrix;
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int leftExcludedSum = 0;
        int topExcludedSum = 0;
        int overlapAddedBack = 0;
        
        if(col1 - 1 >= 0){
            leftExcludedSum = prefixSumMatrix[row2][col1-1];
        }

        if(row1-1 >= 0){
            topExcludedSum = prefixSumMatrix[row1-1][col2];
        }

        if(row1 - 1 >= 0 && col1 - 1 >= 0){
            overlapAddedBack = prefixSumMatrix[row1-1][col1-1];
        }

        return prefixSumMatrix[row2][col2] - leftExcludedSum - topExcludedSum + overlapAddedBack;
    }

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */