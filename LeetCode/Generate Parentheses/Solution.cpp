class Solution {
public:
    void rec(int openCnt, int closedCnt, int parenCnt, vector<string> &ans, string paren){
        if(openCnt > parenCnt || closedCnt > parenCnt) return;
        if(openCnt == parenCnt && openCnt == closedCnt){
            ans.push_back(paren);
            return;
        }
        if(closedCnt < openCnt) rec(openCnt, closedCnt + 1, parenCnt, ans, paren + ")");
        rec(openCnt + 1, closedCnt, parenCnt, ans, paren + "(");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0) return ans;
        rec(0, 0, n, ans, "");
        return ans;
    }
};