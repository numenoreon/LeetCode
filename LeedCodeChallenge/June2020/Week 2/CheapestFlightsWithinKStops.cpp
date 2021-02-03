class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    
        unordered_map<int, vector<pair<int,int>>> graph;

        for(vector<int>& temp: flights){
            graph[temp[0]].push_back(make_pair(temp[1], temp[2]));
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> myPQueue;
        
        vector<vector<int>>costs (n, vector<int>( K+2 , INT_MAX));
        
        costs[src][K+1] = 0;
        myPQueue.push({0, src, K+1});
        
        while(!myPQueue.empty()){
            auto top = myPQueue.top();
            myPQueue.pop();
   
            if(top[1] == dst)
                return top[0];
            
            if(top[2] == 0)
                continue;
            
            for(auto temp: graph[top[1]]){
        
                if(costs[temp.first][top[2]-1] < temp.second+top[0]){
                    continue;
                }
                costs[temp.first][top[2]-1] = temp.second+top[0];
                myPQueue.push({temp.second+top[0], temp.first, top[2]-1});
            }
        }
        
        return -1;
    }
};