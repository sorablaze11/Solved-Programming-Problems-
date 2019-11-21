class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp(text1.size(), vector<int> (text2.size()));
        int ans = 0;
        for(int i = 0; i < text1.size(); i++){
            if(i) for(int j = 0; j < text2.size(); j++) dp[i][j] = dp[i - 1][j];
            for(int  j = 0; j < text2.size(); j++){
                if(j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], ((i && j) ? dp[i - 1][j - 1]: 0) + (text1[i] == text2[j]));
            }
        }
        for(vector<int> x: dp){
            for(int y: x) ans = max(ans, y);//, cout << y << ' ';
            // cout << '\n';
        }
        return ans;
    }
};