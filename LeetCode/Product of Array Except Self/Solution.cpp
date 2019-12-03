class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, cntZero = 0, idx = -1;
        for(int i = 0; i < nums.size(); i++) if(nums[i] == 0){
            cntZero++;
            idx = i;
        }else prod *= nums[i];
        vector<int> ans(nums.size());
        if(cntZero > 1) return ans;
        for(int i = 0; i < nums.size(); i++){
            if(idx != -1){
                if(idx == i) ans[i] = prod;
                else ans[i] = 0;
            }else ans[i] = prod / nums[i];
        }        
        return ans;
    }
};