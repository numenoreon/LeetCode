class Solution {
public:
    
    int  binarySearch(vector <int> &nums, int &target, int left, int right){
        if(left>right)
            return -1;
        
        int middle = (left+right)/2;
        
        if(nums[middle]==target)
            return middle;
        else if(nums[middle]<target)
            return binarySearch(nums, target, middle+1, right);
        else
            return binarySearch(nums, target, left, right-1);
        
    }
    
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size());
    }
};