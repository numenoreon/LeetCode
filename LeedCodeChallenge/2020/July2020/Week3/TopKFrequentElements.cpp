class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty())
            return {};
        
        unordered_map <int, int> mapsMe;
        multimap <int, int, greater <>> freqSorted;
        for(auto &i : nums){
            ++mapsMe[i];
        }
        
        for(auto &i : mapsMe){
            freqSorted.insert({i.second,i.first});
        }
        
        vector <int> result {};

        int counter=0;
        for(auto &i : freqSorted){
            ++counter;
            result.push_back(i.second);
            if(counter==k)
                break;
        }
        
        return result;
    }
};