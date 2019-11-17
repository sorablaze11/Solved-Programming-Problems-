class Solution {
public:
    int left(vector<int> &nums, int lo, int hi){
        int max_ = INT_MIN, temp = 0;
        for(int i = hi; i >= lo; i--){
            temp += nums[i];
            max_ = max(max_, temp);
        }
        return max_;
    }
    
    int right(vector<int> &nums, int lo, int hi){
        int max_ = INT_MIN, temp = 0;
        for(int i = lo; i <= hi; i++){
            temp += nums[i];
            max_ = max(max_, temp);
        }
        return max_;
    }
    
    int rec(vector<int> &nums, int lo, int hi){
        if(lo == hi) return nums[lo];
        if(lo == hi - 1){
            return max(nums[lo], max(nums[hi], nums[lo] + nums[hi]));
        }
        int mid = (lo + hi) / 2;
        int left_max = rec(nums, lo, mid - 1);
        int right_max = rec(nums, mid, hi);
        int left_continuous = left(nums, lo, mid - 1);
        int right_continuous = right(nums, mid, hi);
        // cout << lo << ' ' << mid << ' ' << hi << '\n';
        // cout << left_max << ' ' << right_max << ' ' << left_continuous << ' ' << right_continuous << '\n';
        int max_ = max(left_max, max(right_max, left_continuous + right_continuous));
        return max_;
    }
    
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return rec(nums, 0, nums.size() - 1);
    }
};