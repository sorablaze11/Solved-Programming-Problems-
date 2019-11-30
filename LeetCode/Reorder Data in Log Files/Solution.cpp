class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ret;
        vector<string> digit_log;
        vector<pair<string, string> > letter_log;
        for(int i = 0; i < logs.size(); i++){
            string key = "", value = "";
            bool key_done = false, is_letter = false;
            for(int j = 0; j < logs[i].size(); j++){
                if(logs[i][j] == ' ' && key_done == false){
                    key_done = true;
                    continue;
                }
                if(key_done){
                    value += logs[i][j];
                    if(isalpha(logs[i][j])) is_letter = true;
                }else key += logs[i][j];
            }
            if(is_letter) letter_log.push_back({value + key, logs[i]});
            else digit_log.push_back(logs[i]);
        }
        sort(letter_log.begin(), letter_log.end());
        for(auto x: letter_log) ret.push_back(x.second);
        for(string x: digit_log) ret.push_back(x);
        return ret;
    }
};