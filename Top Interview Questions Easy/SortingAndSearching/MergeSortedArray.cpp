class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=m; i<m+n; i++){

            nums1[i]=nums2[n+m-1-i];
        }
            std::sort(nums1.begin(),nums1.end());
    }
};

_____________________________________________________________________________________________________________

// lazy, better effect will be with sorting by inserting (we have sorted nums1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=m; i<m+n; ++i){
            nums1[i]=nums2[n+m-1-i];
            for(int j=i; j>0; --j){
                if(nums1[j]<nums1[j-1]){
                    swap(nums1[j],nums1[j-1]);
                }
                else{
                    break;
                }
            }
        }
            
    }
};