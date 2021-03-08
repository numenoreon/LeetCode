class Solution {
public:
    void fillVector(vector<int>& nums, vector <vector <int> > &results, vector <int> temp, int index){
        if(index==nums.size()){
            results.push_back(temp);
            return ;
        }
        fillVector(nums, results, temp, index+1);
        temp.push_back(nums[index]);
        fillVector(nums, results, temp, index+1);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int> > results;
        fillVector(nums, results, {}, 0);
        
        return results;
    }
};