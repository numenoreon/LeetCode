class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { 
        int totalPetrol=0, N=gas.size();
    
        for(int i=0;i<N;i++)
            totalPetrol+=(gas[i]-cost[i]);
    
        if(totalPetrol<0)
            return -1;
    
        int fuelLeft=0, startPosition=0;
    
        for(int i=0;i<N;i++){
            fuelLeft+=gas[i]-cost[i];
            if(fuelLeft<0){
                startPosition=i+1;
                fuelLeft=0;
            }
        }
        
        return startPosition;    
    }
};