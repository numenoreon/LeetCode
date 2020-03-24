class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map <int, int> mapsMe;
            
        for(int i=0; i<arr2.size(); ++i){
            mapsMe[arr2[i]]=i+1;  
        }
        
        for(int i=0; i<arr1.size(); ++i){
            if(mapsMe[arr1[i]]==0)
                mapsMe[arr1[i]]=INT_MAX;
        }
            
        sort(arr1.begin(), arr1.end(), [&](const int &a, const int &b){
                return mapsMe[a]<mapsMe[b] || (mapsMe[a]==INT_MAX && mapsMe[b]==INT_MAX && a<b);
        });
            
        return arr1;
    }
};