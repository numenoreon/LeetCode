class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector <int> occurenceCounter (26);
        for (const auto &ch :  tiles) {
            ++occurenceCounter[ch - 'A'];
        }
        int result = 0;
        rec(occurenceCounter, result);
        return result;
    }
    
    void rec(vector <int> table, int &result) {
        for(int i = 0; i < 26; ++i) {
            if (table[i]){
                --table[i];
                result++;
                rec(table, result);
                ++table[i];
            }
        }
    }
};