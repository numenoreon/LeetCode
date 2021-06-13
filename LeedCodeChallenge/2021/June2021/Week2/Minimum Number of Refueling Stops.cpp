class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(stations.size()==0 || target<=startFuel)
            return target>startFuel? -1: 0;
        
        priority_queue <int> myPDQueue;
        int pos = startFuel;
        int next = 0;
        int stop = 0;
        
        while( (next<stations.size() && pos>=stations[next][0]) || !myPDQueue.empty())
        {
            while( next<stations.size() && pos>=stations[next][0] )
                myPDQueue.push(stations[next++][1]);
            pos+=myPDQueue.top();
            myPDQueue.pop();
            ++stop;
            if(pos>=target)
                return stop;
        }
        return -1;
    }
};