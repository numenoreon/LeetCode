class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> result (num+1, 0);
        
        for(int i=0; i<=num; ++i){
            bitset <32> my(i);
            result[i]=my.count();
        }
        
        return result;
    }
};