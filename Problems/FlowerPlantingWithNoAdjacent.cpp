/*

1. make vector with list of all adjacent garden for each garden
2. make vector with avaiable colors for all garden
3. one by one pick first possible color, after picking disable this color for adjacent garden

*/
class Solution {
public:
    void chooseColor(vector < vector <int> > &colorAvaiable, vector<int> &res, vector<vector<int>> &G, int pos){
        if(colorAvaiable[pos][0]==1){
            res[pos]=1;
            for(int i=0; i<G[pos].size(); ++i){
                colorAvaiable[G[pos][i]][0]=-1;
            }
            return ;
        }
        else if(colorAvaiable[pos][1]==2){
            res[pos]=2;
            for(int i=0; i<G[pos].size(); ++i){
                colorAvaiable[G[pos][i]][1]=-1;
            }
            return ;
        }
        else if(colorAvaiable[pos][2]==3){
            res[pos]=3;
            for(int i=0; i<G[pos].size(); ++i){
                colorAvaiable[G[pos][i]][2]=-1;
            }
            return ;
        }
        else if(colorAvaiable[pos][3]==4){
            res[pos]=4;
            for(int i=0; i<G[pos].size(); ++i){
                colorAvaiable[G[pos][i]][3]=-1;
            }
            return ;
        }
    }
    
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N);
        vector<vector<int>> G(N);
    
        for (vector<int>& p : paths) {
            G[p[0] - 1].push_back(p[1] - 1);
            G[p[1] - 1].push_back(p[0] - 1);
        }
        vector < vector <int> > colorAvaiable(N, {1,2,3,4});
        for(int i=0; i<N; ++i){
            chooseColor(colorAvaiable, res, G, i);
        }
        
        return res;
    }
};