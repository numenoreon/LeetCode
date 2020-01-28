bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        if(n == 1) return 1;
        
        int start = 1, stop = n;
        
        while(start < stop)
        {
            int piwot = start + (stop - start)/2;
            if( isBadVersion(piwot)) 
                stop = piwot;
            else
                start = piwot+1;
        }
        
        return start;
    }
};