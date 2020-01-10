class Solution {
public:
    int maxArea(vector<int>& height) {
        int max =0, maxTemp=0;
        for(int i=0; i<height.size()-1; i++){
            for(int j=i+1;j<height.size();j++){
                int temp = height[i]<=height[j] ? height[i] : height[j];
                maxTemp=(temp)*(j-i);
                if(maxTemp>max)
                    max=maxTemp;
            }
        }
    return max;
        
    
    }
};