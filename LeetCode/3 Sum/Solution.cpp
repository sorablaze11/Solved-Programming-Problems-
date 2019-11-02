class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        set<vector<int> > t;
        map<int, int> done;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(done.find(nums[i]) != done.end()) continue;
            int l = i + 1, r = n - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    t.insert(temp);
                    l++, r--;
                }else if(nums[i] + nums[l] + nums[r] > 0) r--;
                else l++;
            }
            done[nums[i]] = 1;
        }
        for(auto x: t){
            ret.push_back(x);
        }
        return ret;
    }
};