class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) : position(0) {
        int maxSize = nestedList.size();
        for(int i=0; i<maxSize; ++i){
            if(nestedList[i].isInteger()){
                nList.push_back(nestedList[i].getInteger());
                continue;
            }
            
            vector <int> temp;
            toIntList(nestedList[i].getList(), temp);

            for(int j=0; j<temp.size(); ++j){
                nList.push_back(temp[j]);
            }
        }
    }
    
    void toIntList(vector <NestedInteger> nList, vector <int> &temp){
        for(int i=0; i<nList.size(); ++i){
            if(nList[i].isInteger()){
                temp.push_back(nList[i].getInteger());
                continue;
            }
            toIntList(nList[i].getList(), temp);
        }
    }
    
    int next() {
        if(!hasNext())
            return -1;
            
        return nList[position++];
    }
    
    bool hasNext() {
        return position<nList.size();
    }
private:
    vector < int > nList;
    int position;
};