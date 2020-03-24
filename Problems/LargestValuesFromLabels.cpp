class Solution {
public:
    
    struct Item{
        int label;
        int value;
    };
    
    void fill_in(vector<int>& values,vector<int>& labels,vector <Item> &result){
        for(int i=0; i<values.size();++i){
            result.push_back({labels[i],values[i]});
        }
    }
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector <Item> result;
        result.reserve(labels.size());
        fill_in(values, labels, result);
        map <int, int> mapsMe;
        int counter=0, numbers=0;
    
        sort(result.begin(),result.end(), [](const Item &a, const Item &b) {
            return a.value > b.value;});

        for(int i=0; i<result.size(); ++i){
            if(++mapsMe[result[i].label]<=use_limit){
                counter+=result[i].value;
                if(++numbers==num_wanted)
                    return counter;    
            }
        }
        
        return counter;
    }
};