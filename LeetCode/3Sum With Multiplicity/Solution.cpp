class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int n = nums.size();
        long ret = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target){
                    if(nums[l] == nums[r]){
                        long cnt = r - l + 1;
                        ret = (ret + cnt * (cnt - 1) / 2) % 1000000007;
                        break;
                    }else{
                        long cnt1 = 1, cnt2 = 1;
                        while(l + 1 < r && nums[l + 1] == nums[l]){
                            l++;
                            cnt1++;
                        }
                        while(r - 1 > l && nums[r - 1] == nums[r]){
                            r--;
                            cnt2++;
                        }
                        l++, r--;
                        ret = (ret + cnt1 * cnt2) % 1000000007;
                    }
                }else if(sum > target) r--;
                else l++;
            }
        }
        return ret;
    }
};