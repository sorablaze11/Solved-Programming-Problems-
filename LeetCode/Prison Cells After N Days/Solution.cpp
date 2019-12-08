class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<string, int> possiblePrisonState;
        string s = "", temp;
        int idx = 0, repeatIdx;
        for(int cell: cells) s += '0' + cell;
        possiblePrisonState[s] = idx++;
        while(true){
            temp = "0";
            for(int i = 1; i < 7; i++){
                if(s[i - 1] == s[i + 1]) temp += "1";
                else temp += "0";
            }
            temp += "0";
            if(possiblePrisonState.find(temp) != possiblePrisonState.end()){
                repeatIdx = possiblePrisonState[temp];
                break;
            }
            possiblePrisonState[temp] = idx++;
            s = temp;
        }
        vector<vector<int> > possible(possiblePrisonState.size(), vector<int>());
        for(auto x: possiblePrisonState){
            vector<int> prison;
            for(char ch : x.first){
                if(ch == '1') prison.push_back(1);
                else prison.push_back(0);
            }
            possible[x.second] = prison;
        }
        if(N <= repeatIdx) return possible[N % possible.size()];
        N -= repeatIdx;
        return possible[repeatIdx + N % (possible.size() - repeatIdx)];
        
    }
};