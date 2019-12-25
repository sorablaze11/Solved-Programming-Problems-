class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 0, num = 1, m = matrix.size(), x, y;
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        int n = matrix[0].size();
        int max_num = m * n;
        vector<vector<int> > done(m, vector<int> (n));
        x = y = 0;
        while(num <= max_num + 1){
            // cout << x << ' ' << y << ' ' << dir << '\n';
            done[x][y] = 1;
            ans.push_back(matrix[x][y]);
            num++;
            if(num == max_num + 1) break;
            if(dir == 0){
                if(y + 1 < n && done[x][y + 1] == 0){
                    y = y + 1;
                }else{
                    dir = (dir + 1) % 4;
                    x = x + 1;
                }
            }else if(dir == 1){
                if(x + 1 < m && done[x + 1][y] == 0){
                    x = x + 1;
                }else{
                    dir = (dir + 1) % 4;
                    y = y - 1;
                }
            }else if(dir == 2){
                if(y - 1 >= 0 && done[x][y - 1] == 0){
                    y = y - 1;
                }else{
                    dir = (dir + 1) % 4;
                    x = x - 1;
                }
            }else{
                if(x - 1 >= 0 && done[x - 1][y] == 0){
                    x = x - 1;
                }else{
                    dir = (dir + 1) % 4;
                    y = y + 1;
                }
            }    
        }
        return ans;
    }
};