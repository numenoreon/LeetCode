class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string, int> mapsMe;
        unordered_map <string, int> mapsMe2;
        vector <string> result;
        
        int j=1;
        int minVal=INT_MAX;
        for(auto &i: list1){
            mapsMe[i]=j;
            ++j;
        }

        j=1;
        for(auto &i: list2){
            if(mapsMe.count(i)){
                mapsMe2[i]=j+mapsMe[i];
                if(minVal>j+mapsMe[i])
                    minVal=j+mapsMe[i];
            }
            ++j;
        }
        
        for(auto &i : mapsMe2)
            if(i.second==minVal)
                result.push_back(i.first);
        
        return result;
    }
};