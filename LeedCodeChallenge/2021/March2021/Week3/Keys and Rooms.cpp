class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int N=rooms.size();
        
        if(N<2)
            return true;
        
        vector<int> myVec(N, 0);
        myVec[0] = 1;
        queue <int> myQueue;
        
        for(auto i : rooms[0])
            myQueue.push(i);
        
        int temp=0;
        while(myQueue.size()) {
            temp = myQueue.front();
            myQueue.pop();
            if(myVec[temp]==1)
                continue;
            myVec[temp] = 1;
            
            for(auto i : rooms[temp])
                myQueue.push(i);
        }
        
        for(int i=0; i<N; ++i)
            if(myVec[i]==0) 
                return false;
        
        return true;
    }
};
