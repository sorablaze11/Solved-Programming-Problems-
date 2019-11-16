class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> email_to_name;
        vector<vector<string> > sorted_accounts;
        unordered_map<string, vector<string> > graph;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                email_to_name[accounts[i][j]] = accounts[i][0];
                graph[accounts[i][1]].push_back(accounts[i][j]);
                graph[accounts[i][j]].push_back(accounts[i][1]);
            }
        }
        set<string> seen;
        for(auto email: graph){
            if(seen.find(email.first) != seen.end()) continue;
            vector<string> component;
            component.push_back(email_to_name[email.first]);
            stack<string> stk;
            stk.push(email.first);
            seen.insert(email.first);
            while(!stk.empty()){
                string node = stk.top();
                component.push_back(node);
                stk.pop();
                for(string other_emails: graph[node]){
                    if(seen.find(other_emails) != seen.end()) continue;
                    seen.insert(other_emails);
                    stk.push(other_emails);
                }
            }
            sort(component.begin() + 1, component.end());
            sorted_accounts.push_back(component);
        }
        return sorted_accounts;
    }
};