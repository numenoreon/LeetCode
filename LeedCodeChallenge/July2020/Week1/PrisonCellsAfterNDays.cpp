class Solution {
public:
    
    void changeCell(vector<int>& cells, vector<int>& prevStage, int N){
        for(int i=0; i<N; ++i){
            for(int j=0; j<cells.size(); ++j){
                if(j==0 || j==cells.size()-1)
                    cells[j]=0;
                else if( (prevStage[j-1]==0 && prevStage[j+1]==0) || (prevStage[j-1]==1 && prevStage[j+1]==1) )
                    cells[j]=1;
                else
                    cells[j]=0;
            }
            prevStage=cells;
        }
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector <int> prevStage = cells;
        
        changeCell(cells, prevStage, 1);
        N=(N-1)%14;
        changeCell(cells, prevStage, N);
        return prevStage;
    }
};