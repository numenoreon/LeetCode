class Solution {
public:
    string customSortString(string S, string T) {
        map <int, char> mapsMeS;
        vector <int> mapsMeT (26);
        
        for(int i=0; i<T.length(); ++i)
            ++mapsMeT[T[i]-'a'];
        
        for(int i=0; i<S.length(); ++i){
            mapsMeS[i]=S[i];
        }
        
        string result;
        
        for(auto &i : mapsMeS){
            while(mapsMeT[i.second-'a']>0){
                result+=i.second;
                --mapsMeT[i.second-'a'];
            }
        }
        
        for(int i=0; i<mapsMeT.size(); ++i){
            while(mapsMeT[i]>0){
                result+=char(i+97);
                --mapsMeT[i];
            }
        }
        
        return result;
    }
};







