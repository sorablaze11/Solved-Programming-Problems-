class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        if(S.size() == 0) return ans;
        int lastOccurence[26] = {0};
        for(int i = 0; i < S.size(); i++) lastOccurence[S[i] - 'a'] = i;
        int l = 0, r = lastOccurence[S[0] - 'a'];
        while(r < S.size()){
            int len = 0;
            while(l < r){
                len++;
                l++;
                r = max(r, lastOccurence[S[l] - 'a']);
            }
            l++;
            r++;
            if(l < S.size()) r = max(r, lastOccurence[S[l] - 'a']);
            ans.push_back(len + 1);
        }
        return ans;
    }
};