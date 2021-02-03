class RandomizedSet {
private:
    map<int, int> position;
    vector<int> actAsSet;
    
public:
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if(position.find(val)!=position.end())
            return false;
        actAsSet.push_back(val);
        position[val] = actAsSet.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(position.find(val)==position.end())
            return false;
        
        int last = actAsSet[actAsSet.size()-1];
        swap(actAsSet[position[val]],actAsSet[position[last]]);
        swap(position[last], position[val]);
        position.erase(val);
        actAsSet.pop_back();
        return true;
        
    }
    
    int getRandom() {
        int i = actAsSet.size();
        int random = rand() % i;
        
        return actAsSet[random];
    }
    

};