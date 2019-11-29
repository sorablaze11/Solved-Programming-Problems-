class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        unordered_map<int, int> unmp;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            unmp[nums[i]]++;
        }
        for(auto x : unmp){
            pq.push({x.second, x.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};