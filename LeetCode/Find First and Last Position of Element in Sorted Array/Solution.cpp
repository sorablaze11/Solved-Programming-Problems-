class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(!binary_search(nums.begin(), nums.end(), target)){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int startPos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int endPos = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        ans.push_back(startPos);
        ans.push_back(endPos - 1);
        return ans;
    }
};