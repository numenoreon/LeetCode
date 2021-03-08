class Trie {
public:

    Trie() {     
    }

    void insert(string word) {
        words.insert(word);
        do {
            begins.insert(word);
            word.pop_back();
        } while (!word.empty());   
    }
    
    bool search(string word) {
        return (words.count(word));
    }
    
    bool startsWith(string prefix) {
        return (begins.count(prefix));
    }
    
    private:
        unordered_set<string> begins;
        unordered_set<string> words;
    
};