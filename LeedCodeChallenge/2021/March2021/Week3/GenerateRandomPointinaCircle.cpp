class Solution {
public:
    Solution(double r, double x_center, double y_center): radius(r), posX(x_center), posY(y_center) {}
    
    vector<double> randPoint() {
        double x = INT_MAX, y = posY + INT_MAX;
    
        while((x-posX)*(x-posX)+(y-posY)*(y-posY) > radius*radius) {
            
            x = (double)rand()/RAND_MAX*(radius*2)+posX-radius;
            y = (double)rand()/RAND_MAX*(radius*2)+posY-radius;
        }
        return {x,y};
        
    }
private:

    double radius;
    double posX;
    double posY;
};