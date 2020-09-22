class Solution {
public:
    string getHint(string secret, string guess) {

        unordered_map <char,set <int>> mapsMe;
        const int N=secret.size();
        vector <int> sndRound;
        sndRound.reserve(N);
        
        for(int i=0; i<N; ++i){
            mapsMe[secret[i]].insert(i);
        }
        
        int A=0,B=0;
        for(int i=0; i<N; ++i){
            if(mapsMe[guess[i]].count(i)){
                ++A;
                mapsMe[guess[i]].erase(i);
            }
            else{
                sndRound.push_back(i);
            }
        }
        
        for(auto &i: sndRound){
            if(!mapsMe[guess[i]].empty()){
                ++B;
                mapsMe[guess[i]].erase(mapsMe[guess[i]].begin());
            }
        }
        
        return to_string(A)+"A"+to_string(B)+"B";
    }
};