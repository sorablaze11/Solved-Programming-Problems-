// O(N) Manacher algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return s;
        string S = "$#";
        for(char ch: s){
            S += ch;
            S += "#";
        }
        vector<int> T(S.size());
        S += "@";
        int C = 0, R = 0, ans = 0, pos;
        for(int i = 1; i < S.size() - 1; i++){
            int mirror = 2 * C - i;
            if(i < R){
                T[i] = min(R - i, T[mirror]);
            }         
            while(S[i + (1 + T[i])] == S[i - (1 + T[i])]){
                T[i]++;
            }
            if(i + T[i] > R){
                C = i;
                R = i + T[i];
            }
            if(ans < T[i]){
                pos = i;
                ans = T[i];
            }
        }
        string ret = "";
        for(int i = pos - ans; i <= pos + ans; i++){
            if(S[i] != '#' && S[i] != '$'  && S[i] != '@') ret += S[i];
        }
        return ret;
    }
};