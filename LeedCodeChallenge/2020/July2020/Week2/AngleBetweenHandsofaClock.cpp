class Solution {
public:
    double angleClock(int hour, int minutes) {
        double myMin=0.0, myHour=0.0;
        myHour=(hour%12 + minutes/60.0)*30;
        myMin=(minutes/60.0)*360;
        
        double result=abs(myMin-myHour);
        return min(result, 360.0-result);
    }
};