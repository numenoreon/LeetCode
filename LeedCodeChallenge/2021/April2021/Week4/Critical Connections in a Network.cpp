class Solution {
    
public:
    
    void dfs(int nodeNumber){
        if(timeStamp[nodeNumber]!=-1)
            return;
        
        timeStamp[nodeNumber]=time;
        lowLink[nodeNumber]=time;
        ++time;
        
        for(auto &i : neighbours[nodeNumber]){
            if(timeStamp[i] == -1){
                parent[i]=nodeNumber;
                dfs(i);
                lowLink[nodeNumber]=min(lowLink[nodeNumber], lowLink[i]);
                if(lowLink[i] > timeStamp[nodeNumber]) 
                    result.push_back({i,nodeNumber});
            } else if(i != parent[nodeNumber])
                    lowLink[nodeNumber] = min(lowLink[nodeNumber], timeStamp[i]); 
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        timeStamp = vector <int> (n, -1);
        lowLink = vector <int> (n, -1);
        parent = vector <int> (n, -1);
        neighbours = vector <vector <int>> (n, vector <int> ());
        
        for(auto &i : connections){
            neighbours[i[0]].push_back(i[1]);
            neighbours[i[1]].push_back(i[0]);
        }
        
        dfs(0);
        
        return result;
    }
    
private:
    int time=0;
    vector <int> timeStamp;
    vector <int> lowLink;
    vector <int> parent;
    vector <vector <int>> result;
    vector <vector <int>> neighbours;

};