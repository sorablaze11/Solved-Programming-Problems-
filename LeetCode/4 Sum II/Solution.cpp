class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ret = 0;
        unordered_map<int, int> freqCnt;
        for(int c: C) for(int d: D) freqCnt[c + d]++;
        for(int a: A){
            for(int b: B){
                if(freqCnt.find(-(a + b)) != freqCnt.end()) ret += freqCnt[-(a + b)];
            }
        }
        return ret;
    }
};