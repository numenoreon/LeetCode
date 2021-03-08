class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
	    if (A.empty())
            return 0;

	    int N = A.size();
	    int total = 0, maxSum = A[0], lastMax = 0, minSum = A[0], lastMin = 0;
        
	    for (int i = 0; i < N; i++) {
		    total += A[i];
            
            lastMax = max(A[i], lastMax+A[i]);
            lastMin = min(A[i], lastMin+A[i]);
            
            maxSum = max(maxSum, lastMax);
            minSum = min(minSum, lastMin);
            
	    }
	return maxSum < 0 ? maxSum : max(maxSum, total - minSum);
    }
};