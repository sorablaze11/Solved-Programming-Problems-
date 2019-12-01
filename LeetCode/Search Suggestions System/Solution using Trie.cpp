class TrieNode{
    public:
    bool is_word;
    TrieNode *children[26];
    set<string> bestThree;
    TrieNode(){
        is_word = false;
        memset(children, NULL, sizeof(children));
    }
};

class Solution {
public:
    TrieNode *root;
    
    void insert(string word){
        TrieNode *node = root;
        for(char ch: word){
            if(node->children[ch - 'a'] == NULL) node->children[ch - 'a'] = new TrieNode();
            ((node->children[ch - 'a'])->bestThree).insert(word);
            while(((node->children[ch - 'a'])->bestThree).size() > 3){
                ((node->children[ch - 'a'])->bestThree).erase(--((node->children[ch - 'a'])->bestThree).end());
            };
            node = node->children[ch - 'a'];
        }
        node->is_word = true;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        for(string product: products) insert(product);
        vector<vector<string> > ans;
        TrieNode *node = root;    
        bool notFound = false;
        for(char ch: searchWord){
            vector<string> temp;
            if(notFound){
                ans.push_back(temp);
                continue;
            }
            if(node->children[ch - 'a'] == NULL){
                notFound = true;
                ans.push_back(temp);
                continue;
            }
            for(string word: node->children[ch - 'a']->bestThree){
                temp.push_back(word);
            }
            ans.push_back(temp);
            node = node->children[ch - 'a'];
        }
        return ans;
    }
};