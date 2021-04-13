class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector <int> result(n, 0);
        
        int start=1, end = start+k+1, i=0;
        bool flip=true;
        
        while(k>=0){
            result[i]=start;
            ++i;
            
            if(flip){
                start+=k;
                flip=false;
            }
            else{
                start-=k;
                flip=true;
            }
            --k;
        }
        
        for(i; i<n; ++i){
            result[i]=end;
            ++end;
        }

        return result;
    }
};