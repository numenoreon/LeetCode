class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int, vector<int>, less<int> > myQueue;
        
        for(int i=0; i<stones.size(); ++i)
            myQueue.push(stones[i]);
        
        int firstStone=0, secondStone=0;
        
        while(myQueue.size()>=2){
            firstStone=myQueue.top();
            myQueue.pop();
            secondStone=myQueue.top();
            myQueue.pop();
            firstStone=firstStone-secondStone;

            if(firstStone==0)
                continue;
            myQueue.push(firstStone);
        }
        
        return myQueue.size() ? myQueue.top() : 0;
    }
};