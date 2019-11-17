class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int over_all_max = 0, temp_max = 0, max_ = INT_MIN;
        for(int num: nums){
            max_ = max(max_, num);
            if(temp_max + num < 0){
                temp_max = 0;
            }else{
                temp_max += num;
            }
            if(over_all_max < temp_max) over_all_max = temp_max;
        }
        if(max_ < 0)  return max_;
        return over_all_max;
    }
};