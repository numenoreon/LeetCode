class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        map <int, int> mapsTarget, mapsArr;
        
        for(int i=0; i<target.size(); ++i)
            ++mapsTarget[target[i]];
        for(int i=0; i<target.size(); ++i)
            ++mapsArr[arr[i]];
        
        for(auto &i : mapsTarget)
            if(i.second != mapsArr[i.first])
                return false;
        
        return true;
    }
};