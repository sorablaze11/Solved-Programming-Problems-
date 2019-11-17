class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        if(t.size() == 0) return false;
        vector<vector<int> > dp(t.size(), vector<int>(s.size()));
        for(int i = 0; i < t.size(); i++){
            int max_ = 0;
            for(int j = 0; j < s.size(); j++){
                if(t[i] == s[j]){
                    dp[i][j] = max(dp[i][j], max_ + 1);
                }else{
                    dp[i][j] = max(dp[i][j], (i > 0 ? dp[i - 1][j]: 0));
                }
                max_ = max(max_, (i > 0 ? dp[i - 1][j] : 0));
                // cout << dp[i][j] << ' ';
            }
            // cout << '\n';
        }
        return (dp[t.size() - 1][s.size() - 1] == s.size() ? true : false);
    }
};