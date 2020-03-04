struct Point{
    int x,y;
};

class Solution {
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector <Point> rottenCord;
        const int X=grid.size();
        const int Y=grid[0].size();
        int fullRotten = X*Y;
        rottenCord.reserve(fullRotten);
        int previousRotten=0,numberOrange=0;
        
        for (int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                if(grid[i][j]==1)
                    ++numberOrange;
                else if(grid[i][j]==2){
                    rottenCord.push_back({i,j});
                    ++numberOrange;
                }
            }
        }
        
        int timer=0;
        previousRotten=rottenCord.size();
        while(rottenCord.size()<numberOrange){
            ++timer;

            for(auto &i : rottenCord){
                int x=i.x;
                int y=i.y;
                
                if(x-1>=0 && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    rottenCord.push_back({x-1,y});
                }

                if(y-1>=0 && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    rottenCord.push_back({x,y-1});
                }
                
                if(x+1<X && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    rottenCord.push_back({x+1,y});
                }
                
                if(y+1<Y && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    rottenCord.push_back({x,y+1});
                }
                    
            }
            if(previousRotten==rottenCord.size())
                return -1;
            previousRotten=rottenCord.size();
        }
        
    return timer;
    }
};