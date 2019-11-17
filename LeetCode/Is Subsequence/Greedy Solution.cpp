class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(char ch : t) if(s[idx] == ch) idx++;
        return (idx == s.size());
    }
};