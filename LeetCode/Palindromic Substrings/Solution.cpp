class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 0) return 0;
        int n = s.size();
        int dp[n][n], ans = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int i = 0; i < n - 1; i++) if(s[i] == s[i + 1]) dp[i][i + 1] = 1;
        for(int sz = 2; sz < n; sz++){
            for(int i = 0; i + sz < n; i++){
                if(dp[i + 1][i + sz - 1] == 1 && s[i] == s[i + sz]) dp[i][i + sz] = 1;
            }
        }
        int posi, posj;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j]) ans++;
            }
        }
        return ans;
    }
};