class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int noOfPiles = piles.size();
        vector<vector<int> > dp(noOfPiles + 1, vector<int>(noOfPiles + 1, -1000001));
        vector<int> suffSum(noOfPiles + 1);
        int sum = 0;
        for(int i = noOfPiles - 1; i >= 0; i--){
            sum += piles[i];
            suffSum[i] = sum;
        }
        for(int i = 0; i <= noOfPiles; i++) dp[noOfPiles][i] = 0;
        for(int i = noOfPiles - 1; i >= 0; i--){
            for(int M = 1; M <= noOfPiles; M++){
                for(int x = 1; x <= 2 * M && i + x <= noOfPiles; x++){
                    dp[i][M] = max(dp[i][M], (suffSum[i] - suffSum[i + x]) - dp[i + x][max(x, M)]);
                }
            }
        }
        return (sum + dp[0][1]) / 2;
    }
};