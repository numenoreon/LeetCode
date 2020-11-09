class Solution {
public:
    
    void backTracking(int position, int sum, int target, vector <int> &candidates, vector <int> &temp,
							 vector < vector <int>> &results){
        if(sum>target)
            return ;
        
        if(sum==target){
            results.push_back(temp);
            return ;
        }
        
        for(int i=position; i<candidates.size(); ++i){
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            backTracking(i, sum, target, candidates, temp, results);
            temp.pop_back();
            sum-=candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector <vector <int>> results;
        vector <int> temp;
        temp.reserve(target);
        
        for(int i=0; i<candidates.size(); ++i){
            temp.push_back(candidates[i]);
            backTracking(i, candidates[i], target, candidates, temp, results);
            temp.pop_back();
        }
        
        return results;
    }
};