class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue <int, vector <int>, greater <int>> pQ;
        const int N = heights.size();
        int temp=0;
        
        for(int i=0; i<N-1; ++i){
            temp = heights[i+1]-heights[i];
            
            if(temp<=0)
                continue;
            pQ.push(temp);
            if(pQ.size() > ladders){
                bricks-=pQ.top();
                pQ.pop();
            }
            
            if(bricks<0)
                return i;
        }
        
        
        return N-1;
    }
};