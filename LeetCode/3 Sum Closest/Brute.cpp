class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Brute force approach O(N^3)
        int closest = INT_MAX, n = nums.size(), ret;
        for(int i = 0; i < n; i++){
            for(int  j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    int temp = abs(target - (nums[i] + nums[j] + nums[k]));
                    if(closest > temp){
                        closest = abs(temp);
                        ret = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return ret;
    }
};