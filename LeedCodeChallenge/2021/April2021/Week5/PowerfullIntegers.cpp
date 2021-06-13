Worsk, but TLE

______________________________________________________________________________

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> result {};
        set<int> mySet;
        
        for (int i = 0; i <= (int) bound / 2; i++) {
            
            for (int j = 0; j <= (int) bound / 2; j++) {
                double p = pow(x, i);
                double p1 = pow(y, j);
                
                if (p + p1 > bound) {
                    break;
                }
                
                
                 mySet.insert(p + p1);
            }
        }
        
        for (auto s: mySet)
            result.push_back(s);
        
        return result;
    }
};