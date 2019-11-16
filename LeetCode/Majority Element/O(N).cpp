class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        int cnt = 0, ans;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0) {
                ans = nums[i];
                cnt++;
            }else {
                if(nums[i] == ans) cnt++;
                else cnt--;
            }
        }
        return ans;
    }
};