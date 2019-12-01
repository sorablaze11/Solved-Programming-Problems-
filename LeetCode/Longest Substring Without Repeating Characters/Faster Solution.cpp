class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int freqCnt[256] = {0};
        int l = 0, r = 0, ans = 0;
        while(r < s.size()){
            freqCnt[s[r]]++;
            if(freqCnt[s[r]] > 1){
                while(l <= r && freqCnt[s[r]] > 1){
                    freqCnt[s[l]]--;
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};