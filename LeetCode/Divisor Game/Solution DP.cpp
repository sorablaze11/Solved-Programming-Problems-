class Solution {
public:
    bool divisorGame(int N) {
        vector<int> dp(N + 1);
        dp[1] = 2;
        for(int i = 2; i <= N; i++){
            int flag = 1;
            for(int j = 1 ; j * j <= i; j++){
                if(i % j == 0 && dp[i - j] == 2){
                    dp[i] = 1;
                    flag = 0;
                    break;
                }
            }
            if(flag) dp[i] = 2;
        }    
        if(dp[N] == 1) return true;
        return false;
    }
};