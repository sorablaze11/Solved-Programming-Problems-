class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[s.size() +  1], maxLength = 0;
        memset(dp, 0, sizeof(dp));
        unordered_map<string, int> words;
        for(string ss: wordDict){
            maxLength = max(maxLength, (int)ss.size());
            words[ss] = 1;
        }
        dp[0] = 1;
        for(int i = 1; i <= s.size(); i++){
            string temp = "";
            for(int j = 0; j < maxLength && i - j >= 1; j++){
                temp = s[i - j - 1] + temp;
                if(words.find(temp) != words.end() && dp[i - j - 1] == 1){
                    dp[i] = 1;
                    break;
                }
            }   
        }
        return dp[s.size()];
    }
};