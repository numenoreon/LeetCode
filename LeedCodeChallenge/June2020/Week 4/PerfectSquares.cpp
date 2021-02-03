class Solution {
public:
    int numSquares(int n) {
        vector<int> table(n+1, n+1);
        table[0] = 0;
        int current = 1;
        for (int i = 1; i < table.size(); ++i) {
            current = 1;
            while (i - (current * current) >= 0) {
                table[i] = min(table[i], table[i-(current * current)]+1); 
                ++current;
            }
        }
        return table[n];
    }
};