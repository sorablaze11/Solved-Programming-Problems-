class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        vector<int> ans;
        while(lo < hi){
            // cout << lo << ' ' << hi << '\n';
            if(numbers[lo] + numbers[hi] == target){
                ans.push_back(lo + 1);
                ans.push_back(hi + 1);
                return ans;
            }
            if(numbers[lo] + numbers[hi] > target) hi--;
            else lo++;
        }
        return ans;
    }
};