class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() == 0) return false;
        int min_ = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++) if(nums[j] > min_ && nums[j] < nums[i]){
                return true;
            }
            min_ = min(min_, nums[i]);
        }
        return false;
    }
};