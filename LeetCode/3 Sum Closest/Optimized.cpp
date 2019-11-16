class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Optimized Approach with binary search O(N^2 * lg(N))
        int closest = INT_MAX, n = nums.size(), ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            for(int  j = i + 1; j < n - 1; j++){
                int l = j + 1, r = n - 1, need = target - (nums[i] + nums[j]);
                while(l < r){
                    int mid = (l + r) >> 1;
                    if(l + 1 == r){
                        if(closest > abs(need - nums[l])){
                            closest = abs(need - nums[l]);
                            ret = nums[i] + nums[j] + nums[l];
                        }
                        if(closest > abs(need - nums[r])){
                            closest = abs(need - nums[r]);
                            ret = nums[i] + nums[j] + nums[r];
                        }
                        break;
                    }else {
                        if(closest > abs(need - nums[mid])){
                            closest = abs(need - nums[mid]);
                            ret = nums[i] + nums[j] + nums[mid];
                        }
                        if(need > nums[mid]) l = mid + 1;
                        else r = mid - 1;
                    }
                }
                if(closest > abs(need - nums[l])){
                    closest = abs(need - nums[l]);
                    ret = nums[i] + nums[j] + nums[l];
                }
                // cout << i << ' ' << j << ' ' << ret << '\n';
            }
        }
        return ret;
    }
};