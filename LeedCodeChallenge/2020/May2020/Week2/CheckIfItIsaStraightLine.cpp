class Solution {
public:
    pair <double, double> checkLine(pair <double, double> &a, pair <double, double> b){
        pair <double, double> temp;
        double W = a.first-b.first, Wa = a.second - b.second, Wb= a.first*b.second-b.first*a.second;
        
        temp.first = Wa/W;
        temp.second = Wb/W;
        return temp;
    }
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        pair <double, double> first = {coordinates[0][0],coordinates[0][1]}, second = {coordinates[1][0],coordinates[1][1]};
        second = checkLine(first, second);

        for(int i = 2; i<coordinates.size(); ++i){
            if(second!=checkLine(first, make_pair(coordinates[i][0],coordinates[i][1])))
                return false;
        }
        
        return true;
    }
};