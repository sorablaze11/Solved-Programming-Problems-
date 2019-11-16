class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ = INT_MAX, max_profit = 0;
        for(int price: prices){
            min_ = min(min_, price);
            max_profit = max(max_profit, price - min_);
        }
        return max_profit;
    }
};