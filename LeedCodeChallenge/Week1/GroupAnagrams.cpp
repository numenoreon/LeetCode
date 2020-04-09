class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map <string, vector<string>> mapping;
        vector <string> tempVector=strs;
        
        for(int i=0; i<tempVector.size();i++){
            sort(tempVector[i].begin(),tempVector[i].end());
            mapping[tempVector[i]].push_back(strs[i]);
        }
  
    vector <vector<string>> results;
        
    for(auto &i : mapping){
            results.push_back(i.second);
        }
        
    return results;     
    }
};  