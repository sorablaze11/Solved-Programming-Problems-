class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> unmp;
        vector<int> ret, buckets[nums.size() + 1];
        for(int i = 0; i < nums.size(); i++){
            unmp[nums[i]]++;
        }
        for(auto x : unmp){
            buckets[x.second].push_back(x.first);
        }
        for(int i = nums.size(); i >= 0; i--){
            if(buckets[i].size() == 0) continue;
            for(int j = 0; j < buckets[i].size(); j++){
                ret.push_back(buckets[i][j]);
                if(ret.size() == k){
                    break;
                }
            }
            if(ret.size() == k){
                    break;
            }
        }
        return ret;
    }
};