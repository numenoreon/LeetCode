class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int, int> mapping;
        
        for(int i=0; i<nums.size(); ++i)
            ++mapping[nums[i]];
        
        struct Node{
            int key;
            int value;
        };
        
        vector <Node> result;
        
        for(auto &i:mapping)
            result.push_back({i.first,i.second});
        
        sort(result.begin(),result.end(),[](const Node &one, const Node &two){
        return one.value>two.value;    
        });
        
        vector <int> answer;
        for(int i=0; i<k; ++i)
            answer.push_back(result[i].key);
        return answer;
    }
};