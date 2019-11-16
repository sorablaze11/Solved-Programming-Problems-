class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32, 0);
        long neg = 0;
        for(int i = 0; i < nums.size(); i++){
            long temp = nums[i];
            if(temp < 0) neg++;
            temp = abs(temp);
            int j = 0;
            while(temp > 0){
                bit[j] += temp % 2;
                j++;
                temp /= 2;
            }
        }
        long ret = 0;
        for(long i = 0, j = 1; i < 32; i++, j *= 2){
            cout << bit[i] << ' ';
            if(bit[i] && (bit[i] % 3)) ret += j;
        }
        if(neg % 3) ret *= -1;
        return ret;
    }
};