class Solution {
public:
    int rec(vector<int> &piles, int idx, int M, int noOfPiles, vector<vector<int> > &dp){
        if(idx >= noOfPiles) return 0;
        if(dp[idx][M] != -1){
            return dp[idx][M];
        }
        int alexGotStones = INT_MIN;
        int tempSum = 0;
        for(int i = 0; i < 2 * M; i++){
            if(!(idx + i < noOfPiles)) break;
            tempSum += piles[idx + i];
            alexGotStones = max(alexGotStones, tempSum - rec(piles, idx + i + 1, max(i + 1, M), noOfPiles, dp));          
        }
        dp[idx][M] = alexGotStones;
        return alexGotStones;
    }
    
    int stoneGameII(vector<int>& piles) {
        vector<vector<int> > dp(105, vector<int>(105, -1));
        int noOfPiles = piles.size();
        int sum = 0;
        for(int x : piles) sum += x;
        return (sum + rec(piles, 0, 1, noOfPiles, dp)) / 2;
    }
};