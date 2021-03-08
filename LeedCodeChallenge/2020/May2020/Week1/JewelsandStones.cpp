class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map <char, int> mapsJewels;
        int counter = 0;
        for(auto &i: J)
            ++mapsJewels[i];
        for(auto &i : S)
            if(mapsJewels[i]>0)
                ++counter;
        
        return counter;
    }
};