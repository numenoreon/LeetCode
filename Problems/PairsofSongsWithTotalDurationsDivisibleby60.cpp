class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if(time.size() < 2) return 0;
        
        map<int, int> mapsMe;
        for(int i = 0; i < time.size(); i++)
        {
            time[i] = time[i] % 60;
            mapsMe[time[i]]++;
        }
        
        int out = 0;
        for(auto it : mapsMe)
        {
            if(it.first == 0) 
                out += mapsMe[it.first]*(mapsMe[it.first]-1)/2;
            
            else if(it.first < 30 && mapsMe.find(60 - it.first)!=mapsMe.end()) 
                out += mapsMe[it.first]*mapsMe[60 - it.first];
            
            else if(it.first == 30)
                out += mapsMe[it.first]*(mapsMe[it.first]-1)/2;
        }
        return out;
    }
};