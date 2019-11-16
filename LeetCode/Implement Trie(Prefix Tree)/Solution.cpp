class TrieNode{
    public:
    bool is_word;
    TrieNode *children[26];
    TrieNode(){
        is_word = false;
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for(char ch: word){
            int ch_idx = ch - 'a';
            if(node->children[ch_idx] == NULL){
                node->children[ch_idx] = new TrieNode();
            }
            node = node->children[ch_idx];
        }
        node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node) return false;
            if(!node->children[word[i] - 'a']) return false;
            node = node->children[word[i] - 'a'];
        }
        return node->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node) return false;
            if(!node->children[prefix[i] - 'a']) return false;
            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */