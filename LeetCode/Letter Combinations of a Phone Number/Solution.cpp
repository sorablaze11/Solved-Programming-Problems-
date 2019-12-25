class Solution {
public:
    vector<string> mapping;
    
    void rec(string digits, int idx, vector<string> &ans, string temp){
        if(idx >= digits.size()){
            ans.push_back(temp);
            return;
        }
        for(char ch: mapping[digits[idx] - '2']) rec(digits, idx + 1, ans, temp + ch);
    }
    
    vector<string> letterCombinations(string digits) {
        mapping.push_back("abc");
        mapping.push_back("def");
        mapping.push_back("ghi");
        mapping.push_back("jkl");
        mapping.push_back("mno");
        mapping.push_back("pqrs");
        mapping.push_back("tuv");
        mapping.push_back("wxyz");
        vector<string> ans;
        if(digits.size() == 0) return ans;
        rec(digits, 0, ans, "");
        return ans;
    }
};