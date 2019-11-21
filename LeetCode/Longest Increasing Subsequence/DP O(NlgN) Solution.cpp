class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp;
        dp.emplace_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if(idx == dp.size()) dp.emplace_back(nums[i]);
            else dp[idx] = nums[i];
        }
        return dp.size();
    }
};