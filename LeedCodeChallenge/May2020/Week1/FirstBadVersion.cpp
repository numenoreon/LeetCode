class Solution {
public:
    int firstBadVersion(int n) 
    {
        long int left=0, right=n;
        while(left<=right){
            int middle = (left+right)/2;
            if(isBadVersion(middle) && !isBadVersion(middle-1)){
                return middle;
            }
            else if(isBadVersion(middle)){
                right=middle-1;
            }
            else{
                left=middle+1;
            }
        }
        return -1;
    }
};