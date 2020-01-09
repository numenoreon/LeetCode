class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
    const int N1 = nums1.size(), N2 = nums2.size();    
        
    vector <int> result;
    
    N1>N2 ? result.reserve(N2) : result.reserve(N1);
            
    if(!is_sorted(nums1.begin(), nums1.end()))
        sort(nums1.begin(), nums1.end());
    if(!is_sorted(nums2.begin(), nums2.end()))
        sort(nums2.begin(), nums2.end());
    
    int i1 = 0, i2 = 0;
    
    while(i1 < N1 && i2 < N2) {
        if(nums1[i1] == nums2[i2]) {
            result.push_back(nums1[i1]);
            i1++;
            i2++;
        }
        else if(nums1[i1] < nums2[i2]) {
            i1++;
        }
        else if(nums1[i1] > nums2[i2]) {
            i2++;
        }
    }
    return result;
}
};