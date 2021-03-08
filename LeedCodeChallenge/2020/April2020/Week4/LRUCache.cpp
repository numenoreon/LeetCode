struct Node{
    int key;
    int value;
};

class LRUCache {
public:
    LRUCache(int cp) : capacity(cp) {
    }
    
    int get(int key) {
        auto it = HashMap.find(key);
        if(it!=HashMap.end()){
            reorganizeList(key,HashMap[key]->value);
            return HashMap[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = HashMap.find(key);        
        
        if(it!=HashMap.end()){
            reorganizeList(key,value);
        }
        else{         
            if(HashMap.size()<capacity){
                Cache.push_front({key,value});
                HashMap[key]=Cache.begin();
            }
            else{
                //cout << Cache.back().key << " " << Cache.back().value << endl;
                HashMap.erase(Cache.back().key);
                Cache.pop_back(); 
                Cache.push_front({key, value});
                HashMap[key] = Cache.begin();
            }
        }
    }
    
private:
    int capacity;
    list <Node> Cache;
    unordered_map <int, list<Node>::iterator > HashMap;

    void reorganizeList( int key, int value ) {
        Cache.erase( HashMap[key] );
        Cache.push_front({key,value});
        HashMap[key] = Cache.begin();
    }
};