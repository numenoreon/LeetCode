class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int counter=0, endPosition=-1;
        
        for(int i=0; i<timeSeries.size(); ++i){
            if(endPosition<=timeSeries[i]){
                counter+=duration;
                endPosition=timeSeries[i]+duration;
            }
    
            else if(endPosition>timeSeries[i]){
                counter+=(duration-(endPosition-timeSeries[i]));
                endPosition=timeSeries[i]+duration;
            }
        }
        
        return counter;
    }
};