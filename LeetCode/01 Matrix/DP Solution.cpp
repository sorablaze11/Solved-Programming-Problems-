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
                ret[i][j] = min(ret[i][j] , min((j - 1 >= 0 ? ret[i][j - 1] : 1000000), (i - 1 >= 0 ? ret[i - 1][j] : 1000000)) + 1);
            }    
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--){
                if(matrix[i][j] == 0)
                {
                    ret[i][j] = 0;
                    continue;
                }
                ret[i][j] = min(ret[i][j], min((j + 1 < m ? ret[i][j + 1] : 1000000), (i + 1 < n ? ret[i + 1][j] : 1000000)) + 1);
            }  
        }
        return ret;
    }
};