class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map <string, int> mapsMe;
        multimap <int, string, greater<int>> mapsYou;
        vector <string> result;
        
        for(auto &i : words)
            ++mapsMe[i];

        for(auto &i : mapsMe)
            mapsYou.insert({i.second,i.first});
      
        auto it = mapsYou.begin();
        
        while(k--){
            result.push_back(it->second);
            ++it;
        }
                
        return result;
    }
};