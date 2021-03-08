        
        













        /*
        
        unordered_map <char, vector <pair <int, int> > > mapsMe;
        
        for(int i=0; i< board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                auto temp = make_pair(i,j);
                mapsMe[board[i][j]].push_back(temp);
            }
        }
        

        
        for(int i=0; i<words.size(); ++i){
            if(!mapsMe[words[i][0]].empty()){
                for(int j=0; j<mapsMe[words[i][0]].size(); ++j){
                    vector < vector <bool> > bTable (board.size(), vector <bool> (board[0].size(),false));
                    dfs(words[i], 0, board, bTable ,mapsMe[words[i][0]][j].first, mapsMe[words[i][0]][j].second);
                }
            }
        }
        
        */