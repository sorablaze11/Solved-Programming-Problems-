class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                int l = j + 1, r = n - 1;
                while(l < r){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(target == sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ret.push_back(temp);
                        if(nums[l] == nums[r]) break;
                        else{
                            while(l + 1 < r && nums[l + 1] == nums[l]) l++;
                            while(r - 1 > l && nums[r - 1] == nums[r]) r--;
                            l++, r--;
                        }
                    }else if(sum < target) l++;
                    else r--;
                }                
                while(j + 1 < n && nums[j] == nums[j + 1]) j++;
            }
             while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return ret;
    }
};