class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {    
        vector<vector<int>>result;
        const int N=intervals.size();
        if(N==0||N==1)
            return intervals;
        
        result.reserve(intervals.size());
        sort(intervals.begin(),intervals.end());
        
        result.push_back({intervals[0][0],intervals[0][1]});
        int pos=0;
    
        for(int i=1;i<N;i++){
            if(intervals[i][0]<=result[pos][1])  
                result[pos][1]=max(result[pos][1],intervals[i][1]);
            else{
                result.push_back({intervals[i][0],intervals[i][1]});
                pos++;
            }
        }
    return result;
    }
};