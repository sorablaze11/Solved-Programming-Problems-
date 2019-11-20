class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int arrLen = arr.size();
        vector<vector<pair<int, int> > > dp(arrLen, vector<pair<int, int> > (arrLen, {INT_MAX, 0}));
        for(int i = 0; i < arrLen; i++) dp[i][i].first = 0, dp[i][i].second = arr[i];
        for(int sz = 1; sz < arrLen; sz++){
            for(int i = 0; i < arrLen; i++){
                if(!(i + sz < arrLen)) break;
                int minProduct = dp[i][i + sz].first, maxValue;
                for(int j = 0; j < sz; j++){
                    int tempValue = dp[i][i + j].first + dp[i + j + 1][i + sz].first + dp[i][i + j].second * dp[i + j + 1][i + sz].second;
                    if(tempValue < minProduct){
                        minProduct = tempValue;
                        maxValue = max(dp[i][i + j].second, dp[i + j + 1][i + sz].second);
                    }
                }
                dp[i][i + sz] = {minProduct, maxValue};
            }
        }
        
        return dp[0][arrLen - 1].first;
    }
};