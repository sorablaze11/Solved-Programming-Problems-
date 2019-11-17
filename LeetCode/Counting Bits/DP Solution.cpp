class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bitCount(num + 1);
        if(num == 0) return bitCount;
        if(num == 1){
            bitCount[1] = 1;
            return bitCount;
        }
        if(num > 1) bitCount[1] = bitCount[2] = 1;
        int prevPowerOfTwo = 2;
        for(int i = 3; i <= num; i++){
            if(prevPowerOfTwo * 2 == i){
                bitCount[i] = 1;
                prevPowerOfTwo *= 2;
                continue;
            }
            bitCount[i] = 1 + bitCount[i - prevPowerOfTwo];
        }
        return bitCount;
    }
};