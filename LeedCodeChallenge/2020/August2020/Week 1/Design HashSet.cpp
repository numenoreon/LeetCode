class MyHashSet {
public:
    vector<list<int>> vec;

    MyHashSet() {
        vec = vector<list<int>> (128);
    }
    
    inline int GetHash(int key) {
        int h = hash<int>{}(key);
        int hash_mod = h % vec.size();
        return hash_mod;
    }
    
    void add(int key) {
        int hash = GetHash(key);
        if (contains(key, hash))
            return ;
        auto &l = vec[hash];
        l.push_back(key);
        return ;
    }
    
    inline void remove(int key, int hash) {
        auto &l = vec[hash];
        auto it = l.begin();
        while (it != l.end()) {
            if (*it != key) {
                ++it;
                continue;
            }
            l.erase(it);
            return ;
        }
        return ;
    }
    void remove(int key) {
        remove(key, GetHash(key));
        return ;
    }
    
    inline bool contains(int key, int hash) {
        const auto &l = vec[hash];
        for (int n : l) {
            if (n == key)
                return true;
        }
        return false;
    }
    bool contains(int key) {
        return contains(key, GetHash(key));
    }
};