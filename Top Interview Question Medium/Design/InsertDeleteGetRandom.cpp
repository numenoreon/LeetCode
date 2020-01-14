class RandomizedSet {
    
private:
    vector<int> actAsSet;
    
public:
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = find(actAsSet.begin(), actAsSet.end(), val);
        if(it!=actAsSet.end())
            return false;
        actAsSet.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = find(actAsSet.begin(), actAsSet.end(),val);
        if(it==actAsSet.end())
            return false;
        
        *it=actAsSet[actAsSet.size()-1];
        actAsSet.pop_back();  
        return true;
        
    }
    
    int getRandom() {
        int i = actAsSet.size();
        int random = rand() % i;
        
        return actAsSet[random];
    }
};