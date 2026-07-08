class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m,n;
        
        for(m = 0;m< matrix.size();m++){
            for(n = 0;n<matrix[m].size();n++){
                if(matrix[m][n]== target){
                    return true;
                }
            }
        }
        return false;
    }
};