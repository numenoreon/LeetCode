struct TrieNode{
    map<char,TrieNode*> child;
    bool isWord;
    TrieNode() : isWord(false) {}
};

class WordDictionary {
public:
/** Initialize your data structure here. */
TrieNode* root;
WordDictionary() {
    root=new TrieNode();
}
~WordDictionary(){
    root->child.clear();
    delete(root);
}

/** Adds a word into the data structure. */
void addWord(string s) {
    TrieNode* node=root;
    for(int i=0; i<s.size(); i++){
        map<char, TrieNode*> &mp=node->child;
        if(mp.find(s[i])==mp.end()){
            mp[s[i]]=new TrieNode();
        }
        node=mp[s[i]];
    }
    node->isWord=true;
}

bool search(string s) {
    return helper(s.c_str(), root);
}

bool helper(const char* s, TrieNode* temp){
    TrieNode* node=temp;
    for(int i=0; s[i]; i++){
        map<char, TrieNode*> &mp=node->child;
        if(s[i]!='.'){
            if(mp.find(s[i])==mp.end()){
                return false;
            }
            node=mp[s[i]];
        }
        else{
            for(auto it=mp.begin(); it!=mp.end(); it++){
                TrieNode* res=it->second;
                if(helper(s+i+1, res)) return true;
            }
            return false;
        }
    }
    return node->isWord;
}
};