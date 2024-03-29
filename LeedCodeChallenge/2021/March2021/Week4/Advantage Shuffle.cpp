class Solution {
public:
    static bool cmp(int a, int b){
        return a>b;
    }
    
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> b = B;
        vector<int>res;
        
        sort(A.begin(),A.end(),cmp);
        sort(B.begin(),B.end(),cmp);
        int i=0; 
        int j = 0;
        multimap<int,int> mapsMe;
        int k = A.size()-1;
        while(i<A.size() && j < B.size()){
            if(A[i]>B[j]){
                mapsMe.insert(pair<int,int>(B[j],A[i]));
                i++;
            }else{
                mapsMe.insert(pair<int,int>(B[j],A[k]));
                k--;
            }
            j++;
        }
        for(int c = 0; c<A.size(); c++){
            auto it = mapsMe.find(b[c]);
            res.push_back(it->second);
            mapsMe.erase(it);
        }
        return res;
    }
};