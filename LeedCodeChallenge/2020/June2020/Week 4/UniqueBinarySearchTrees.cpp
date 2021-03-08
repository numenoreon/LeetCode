class Solution {
public:
    int numTrees(int n) {
        int result = 0;
        vector<int> counter;
        counter.push_back(1);
        for(int i = 1; i <= n; i++){
            for(int j = 1;j <= i;j++)
                result += counter[j-1]*counter[i-j];     
            counter.push_back(result);
            result = 0;
        }
        return counter[n];  
    }
};