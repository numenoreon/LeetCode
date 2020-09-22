class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector <int> &first, vector <int> &second){
           return first[1]<second[1]; 
        });
        
        int passangerCounter=0;
        
        map <int, int> mapsMe;
        set <int> busStop;
        
        for(int i=0; i<trips.size(); ++i){

            while(!busStop.empty() && *busStop.begin()<=trips[i][1]){
                passangerCounter-=mapsMe[*busStop.begin()];
                busStop.erase(busStop.begin());
            }

            if(passangerCounter+trips[i][0]>capacity){
                return false;
            }

            passangerCounter+=trips[i][0];
            mapsMe[trips[i][2]]+=trips[i][0];
            busStop.insert(trips[i][2]);
        }     
        return true;
    }  
};