class Solution {
public:
    bool isRobotBounded(string instructions) {
        int change=0;
        pair <int, int> pStart {0,0};
        
        for(int i=0; i<4; ++i){
            for(auto &i : instructions){
                if(i=='G'){
                    if(change==0)
                        pStart.second+=1;
                    else if(change==90 || change == -270)
                        pStart.first+=1;
                    else if(change==180 || change == -180)
                        pStart.second-=1;
                    else if(change==270 || change == -90)
                        pStart.first-=1;
                }
                else if(i=='L')
                    change-=90;
                else if(i=='R')
                    change+=90;
                if( change== 360 || change == -360){
                    change=0;
                }
            }
            
            if(pStart.first==0 && pStart.second==0)
                return true;
        }
        
        return false;
    }
};