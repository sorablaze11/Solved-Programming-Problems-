class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool word = false;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ' ' && word) break;
            if(s[i] != ' ') word = true, len++;;
        }
        return len;
    }
};