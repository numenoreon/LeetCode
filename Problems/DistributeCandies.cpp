class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map <int, int> mapsMe;
        
        for(auto &i : candies){
            ++mapsMe[i];
        }
        
        return mapsMe.size()<candies.size()/2 ? mapsMe.size() : candies.size()/2;
        
    }
};