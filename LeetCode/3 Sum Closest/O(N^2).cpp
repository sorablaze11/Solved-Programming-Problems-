class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Optimized Approach
        int closest = INT_MAX, n = nums.size(), ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target){
                    return target;
                }else if(sum > target) r--;
                else l++;
                if(closest > abs(target - sum)){
                    closest = abs(target - sum);
                    ret = sum;
                }
            }
        }
        return ret;
    }
};