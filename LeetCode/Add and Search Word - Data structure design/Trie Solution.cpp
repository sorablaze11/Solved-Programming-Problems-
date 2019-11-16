class TrieNode{
    public:
    bool is_word;
    TrieNode *children[26];
    TrieNode(){
        is_word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. **/
    TrieNode *root = new TrieNode();
    
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
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
    
    // Recursive search in trie.
    bool recursive_search(string word, TrieNode* node, int idx){
        cout << word[idx] << ' ';
        if(node == NULL) return false;
        if(idx == word.size() - 1){
            if(word[idx] == '.'){
                for(int i = 0; i < 26; i++) if(node->children[i] && (node->children[i])->is_word) return true;
            }else{
                if(node->children[word[idx] - 'a'] && (node->children[word[idx] - 'a'])->is_word) return true;
            }
            return false;
        }
        if(word[idx] == '.'){
            bool flag = false;
            for(int i = 0; i < 26; i++){
                if(node->children[i]){
                    flag |= recursive_search(word, node->children[i], idx + 1);
                }
            }
            return flag;
        }else{
            if(node->children[word[idx] - 'a']){
                return recursive_search(word, node->children[word[idx] - 'a'], idx + 1);
            }
        }
        return false;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return recursive_search(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */