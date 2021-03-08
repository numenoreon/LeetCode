class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for(auto &i : nums)
            add(i);
    }
    
    int showFirstUnique() {
        if(myList.empty())
            return -1;
        return myList.front();
    }
    
    void add(int value) {
        if(mapsMe[value]==1){
            myList.erase(mapsIterator[value]);
        }
        ++mapsMe[value];
        if(mapsMe[value]==1){
            myList.push_back(value);
            mapsIterator[value]=--myList.end();
        }
    }
private:
    map <int, int> mapsMe; //maps to count occurence
    map <int, list<int>::iterator> mapsIterator; // maps with iterator to element to avoid time limit exceed
    list <int> myList; // list with unique elements
};
