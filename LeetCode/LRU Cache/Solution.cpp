class LRUCache {
private:
    int C;
    unordered_map<int, list<int>::iterator> m;
    unordered_map<int, int> key_to_val;
    list<int> l;
public:
    LRUCache(int capacity) {
        C = capacity;
    }
    
    int get(int key) {
        if(key_to_val.find(key) == key_to_val.end()) return -1;
        list<int>::iterator it = m[key];
        l.erase(it);
        l.push_front(key);
        m[key] = l.begin();
        return key_to_val[key];
    }
    
    void put(int key, int value) {
        // cout << l.size() << ' ' << C << '\n';
        if(key_to_val.find(key) == key_to_val.end()){
            if(l.size() == C){
                int last = l.back();
                l.pop_back();
                key_to_val.erase(last);
                m.erase(last);
            }
        }else{
            l.erase(m[key]);
            m.erase(key);
            key_to_val.erase(key);
        }
        l.push_front(key);
        m[key] = l.begin();
        key_to_val[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */