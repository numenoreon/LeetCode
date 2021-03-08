class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        
        auto comp = [](vector <int> &vecA, vector <int> &vecB){
            if(vecA[0]==vecB[0])
                return vecA[1]<vecB[1];
            return vecA[0]<vecB[0];
        };

        sort(points.begin(), points.end(), comp);

        int counter=1;
        int maxBegin=points[0][0], minEnd=points[0][1];
        
        for(int i=1; i<points.size(); ++i){
            if(points[i][0]>minEnd){
                ++counter;
                maxBegin=points[i][0];
                minEnd=points[i][1];
            }
            else{
                maxBegin=max(maxBegin, points[i][0]);
                minEnd=min(minEnd, points[i][1]);
                if(maxBegin>minEnd){
                    ++counter;
                    maxBegin=points[i][0];
                    minEnd=points[i][1];
                }
            }
        }
     
        return counter;
    }
};