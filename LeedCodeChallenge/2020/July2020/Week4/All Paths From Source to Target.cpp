class Solution {
public:
    
    void helper(vector<vector<int>>& graph, vector<int> candidate, int target, vector<vector<int>>& result){
        if (candidate.back() == target){
            result.push_back(candidate);
            return;
        }
        
        for (const auto& num : graph[candidate.back()]) {
            candidate.push_back(num);
            helper(graph, candidate, target, result);
            candidate.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        const int N = graph.size(); 
        helper(graph, {0}, N - 1, result); 
        
        return result;
    }
};