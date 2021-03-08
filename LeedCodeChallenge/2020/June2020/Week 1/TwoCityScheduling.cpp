class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        auto comp = [&costs](const vector <int> &a, const vector <int> &b){
            return a[0]-a[1] > b[0]-b[1];
        };
        
        sort(costs.begin(), costs.end(), comp);
        int sum=0;
        
        for(int i=0; i<costs.size(); ++i){
            if(i < costs.size()/2)
                sum+=costs[i][1];
            else
                sum+=costs[i][0];
        }
        
        return sum;
    }
};