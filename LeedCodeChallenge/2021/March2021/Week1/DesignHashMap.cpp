class MyHashMap {
public:
    MyHashMap() {
        myVec = vector <int> (1000000, -1);
    }
    
    void put(int key, int value) {
        myVec[key]=value;
    }
    
    int get(int key) {
        return myVec[key];
    }
    
    void remove(int key) {
        myVec[key]=-1;
    }
private:
    vector <int> myVec;
};
