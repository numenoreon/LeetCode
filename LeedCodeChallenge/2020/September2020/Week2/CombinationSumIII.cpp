class Solution {
public:
    
    void findSum(int pos, int k, int n, vector <int> temp, vector <vector <int> > &result, int sum){
        sum+=pos;
        temp.push_back(pos++);
        
        if(temp.size()==k){
            if(sum==n)
                result.push_back(temp);
            return;
        }
        
        for(int i=pos; i<10; ++i){
            findSum(i, k, n, temp, result, sum);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>55 || k>9)
            return {};
        vector < vector <int> > result;
        
        for(int i=1; i<10; ++i){
            findSum(i, k, n, vector <int> (), result, 0);
        }
        
        
        return result;        
    }
};