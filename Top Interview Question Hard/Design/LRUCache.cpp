struct Node{
    int key;
    int value;
};

class LRUCache {
public:
    LRUCache(int cp) : capacity(cp) {
    }
    
    int get(int key) {
        auto it=find_if(data.begin(),data.end(),[&](const Node &temp){
            return temp.key==key;
        });
        
        if(it!=data.end()) {
            int temp = it->value;
            reconfigureLRU(it);
            return temp;
        }
        //else if(it==data.end())
            return -1;
    }
    
    void put(int key, int value) {
        auto it=find_if(data.begin(),data.end(),[&](const Node &temp){
            return temp.key==key;});
        
        if(it!=data.end()){
            it->value=value;
            reconfigureLRU(it);  
        }
        else{         
            if(data.size()<capacity)
                data.push_back({key,value});
            else{
                reconfigureLRU(data.begin());
                data[capacity-1]={key,value};
            }
        }
    }
    
private:
    int capacity;
    vector <Node> data;
    
    void reconfigureLRU(vector<Node>::iterator it){
        int i = it-data.begin();
        for(int j=i; j<data.size()-1;++j){
            swap(data[j],data[j+1]);
        }
    } 
};
