class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int> > ret(n, vector<int>(m, 1000000));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0)
                {
                    ret[i][j] = 0;
                    continue;
                }
                int temp = 1000000;
                // Check left
                for(int k = j - 1; k >= 0; k--) 
                {
                    temp = min(temp, ret[i][k] + (j - k));
                    if(matrix[i][k] == 0)
                    {
                        temp = min(temp, j - k);   
                        break;
                    }
                }
                // Check top
                for(int k = i - 1; k >= 0; k--) 
                {
                    temp = min(temp, ret[k][j] + (i - k));
                    if(matrix[k][j] == 0)
                    {
                        temp = min(temp, i - k);   
                        break;
                    }
                }
                ret[i][j] = min(temp, ret[i][j]);
            }    
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--){
                if(matrix[i][j] == 0)
                {
                    ret[i][j] = 0;
                    continue;
                }
                int temp = 1000000;
                // Check right
                for(int k = j + 1; k < m; k++) 
                {
                    temp = min(temp, ret[i][k] + (k - j));
                    if(matrix[i][k] == 0)
                    {
                        temp = min(temp, k - j);   
                        break;
                    }
                }
                // Check down
                for(int k = i + 1; k < n; k++) 
                {
                    temp = min(temp, ret[k][j] + (k - i));
                    if(matrix[k][j] == 0)
                    {
                        temp = min(temp, k - i);   
                        break;
                    }
                }
                ret[i][j] = min(temp, ret[i][j]);
            }    
        }
        return ret;
    }
};