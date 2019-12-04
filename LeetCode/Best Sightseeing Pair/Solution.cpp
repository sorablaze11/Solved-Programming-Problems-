class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0, max_ = 0;
        for(int a: A){
            ans = max(ans, a + max_);
            max_ = max(max_, a) - 1;
        }
        return ans;
    }
};