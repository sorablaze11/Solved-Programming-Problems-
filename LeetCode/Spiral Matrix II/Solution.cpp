class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir = 0, num = 1, x, y;
        vector<vector<int> > matrix(n, vector<int>(n));
        x = y = 0;
        int max_num = n * n;
        while(num <= max_num + 1){
            // cout << x << ' ' << y << ' ' << dir << '\n';
            matrix[x][y] = num;
            num++;
            if(num == max_num + 1) break;
            if(dir == 0){
                // cout << "DIR 1\n";
                if(y + 1 < n && matrix[x][y + 1] == 0){
                    y = y + 1;
                }else{
                    dir = (dir + 1) % 4;
                    x = x + 1;
                }
            }else if(dir == 1){
                // cout << "DIR 2\n";
                if(x + 1 < n && matrix[x + 1][y] == 0){
                    x = x + 1;
                }else{
                    dir = (dir + 1) % 4;
                    y = y - 1;
                }
            }else if(dir == 2){
                // cout << "DIR 3\n";
                if(y - 1 >= 0 && matrix[x][y - 1] == 0){
                    y = y - 1;
                }else{
                    dir = (dir + 1) % 4;
                    x = x - 1;
                }
            }else{
                // cout << "DIR 4\n";
                if(x - 1 >= 0 && matrix[x - 1][y] == 0){
                    x = x - 1;
                }else{
                    dir = (dir + 1) % 4;
                    y = y + 1;
                }
            }
        }
        return matrix;
    }
};