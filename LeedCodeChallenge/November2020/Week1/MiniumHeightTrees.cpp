class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty())
            return {0};
        
        vector <int> edgeCounter(n,0);
        vector <vector <int>> edgeList (n, vector <int> ());
        
        for(int i=0; i<edges.size(); ++i){
            ++edgeCounter[edges[i][0]] , ++edgeCounter[edges[i][1]];
            edgeList[edges[i][0]].push_back(edges[i][1]);
            edgeList[edges[i][1]].push_back(edges[i][0]);
        }

        queue <int> myQueue;
        
        for(int i=0; i<n; ++i){
            if(edgeCounter[i]==1){
                myQueue.push(i);
            }
        }
        
        vector <int> result;
        result.reserve(n);
        
        int tempNode=-1;
        
        while(myQueue.size()){
            
            result.clear();
            int N = myQueue.size();
            while(N--){
                tempNode=myQueue.front();
                myQueue.pop();
                result.push_back(tempNode);
                for(int j=0; j<edgeList[tempNode].size(); ++j){
                    --edgeCounter[edgeList[tempNode][j]];
                    if(edgeCounter[edgeList[tempNode][j]]==1)
                        myQueue.push(edgeList[tempNode][j]);
                }
            }
            
        }
        
        return result;
    }
};