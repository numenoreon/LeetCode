class Solution {
    public:
    int search(vector <int> & nums, int target) {
        int left=0, right=nums.size()-1, middle=0;

        while(left<=right){
            middle=(left+right)/2;
            if(nums[middle]==target)
                return middle;
            else if(nums[middle]>nums[right]){
                if(target>nums[right]&&target<nums[middle])
                    right=middle-1;
                else
                    left=middle+1;
            }
            else if(nums[middle]<nums[right]){
                if(target>nums[middle]&&target<=nums[right])
                    left=middle+1;
                else
                    right=middle-1;
            }
            else
                break;
        }
    return -1;
    }
};