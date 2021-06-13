class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n = arr.size();
        int sum = 0;
        int ans = 0;
        int mod = 1000000007;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++)
        {
            sum = target-arr[i];
            
            int left = i+1;
            int right = n-1;
            
            while(left < right)
            {
                if(arr[left]+arr[right] < sum)
                    left++;
                else if(arr[left]+arr[right] > sum)
                    right--;
                else
                {
                    int j = left;
                    int k = right;
                    int count1 = 0, count2 = 0;
                    
                    while(j <= right && arr[j] == arr[left])
                    {
                        count1++;
                        j++;
                    }
                    if(j > right)
                    {
                        int ans_here = (count1*(count1-1))/2;
                        ans = (ans+ans_here)%mod;
                    }
                    else
                    {
                        while(k >= j && arr[k] == arr[right])
                        {
                            count2++;
                            k--;
                        }
                        ans = (ans+(count1*count2)%mod)%mod;
                    }
                    left = j;
                right = k;
               }
                
            }
        }
        return ans;
    }
};