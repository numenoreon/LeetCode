class Solution {
public:
    
    void makeVector(int target, vector<int>& candidates, vector <int> &myVec, vector <vector <int> > &result, int j, int sum){
        if(sum>target){
            return ;
        }
        if(sum==target){
            result.push_back(myVec);
        }
        
        for(int i=j; i<candidates.size(); ++i){
            sum+=candidates[i];
            myVec.push_back(candidates[i]);
            makeVector(target, candidates, myVec, result, i, sum);
            myVec.pop_back();
            sum-=candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector <int> > result;
        vector <int> myVec;
        makeVector(target, candidates, myVec, result, 0, 0);
        return result;
    }
};