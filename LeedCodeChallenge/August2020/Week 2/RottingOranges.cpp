class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.empty())
            return -1;
        
        vector <pair <int, int>> rotten;
        int orangeNumber = 0;
        
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]==2){
                    rotten.push_back({i,j});
                    ++orangeNumber;
                }
                else if(grid[i][j]==1)
                    ++orangeNumber;
            }
        }
        
        if(rotten.size()==orangeNumber)
            return 0;
        
        int counter=0;
        
        while(1){
            unsigned int sizeRotten= rotten.size();
            
            for(int i=0; i<sizeRotten; ++i){
                if(rotten[i].first-1>=0 && grid[rotten[i].first-1][rotten[i].second]==1){
                    grid[rotten[i].first-1][rotten[i].second]=2;
                    rotten.push_back({rotten[i].first-1,rotten[i].second});
                }
                
                if(rotten[i].first+1<grid.size() && grid[rotten[i].first+1][rotten[i].second]==1){
                    grid[rotten[i].first+1][rotten[i].second]=2;
                    rotten.push_back({rotten[i].first+1,rotten[i].second});
                }
                
                if(rotten[i].second -1 >=0 && grid[rotten[i].first][rotten[i].second-1]==1){
                    grid[rotten[i].first][rotten[i].second-1]=2;
                    rotten.push_back({rotten[i].first,rotten[i].second-1});
                }
                
                if(rotten[i].second +1 < grid[0].size() && grid[rotten[i].first][rotten[i].second+1]==1){
                    grid[rotten[i].first][rotten[i].second+1]=2;
                    rotten.push_back({rotten[i].first,rotten[i].second+1});
                }
        }
            
            ++counter;
            
            if(rotten.size()==orangeNumber)
                return counter;
            else if(rotten.size()==sizeRotten)
                return -1;
        }
        
        
        return counter;
        
    }
};