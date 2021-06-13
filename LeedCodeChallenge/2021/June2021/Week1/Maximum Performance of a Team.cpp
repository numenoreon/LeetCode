class Solution {
public:

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector < vector<long long> > myVec;
        for(long long i=0; i<n; i++){
            myVec.push_back({efficiency[i], speed[i]});
        }
        sort(myVec.rbegin(), myVec.rend());
        
        priority_queue<long long, vector<long long>, greater<long long> > myPQueue;
        long long maxPerf = LLONG_MIN;
        long long speedSum = 0;
        
        for(auto v: myVec){            
            long long currEf = v[0];
            long long currSp = v[1];
            
            speedSum = speedSum + currSp;
            myPQueue.push(currSp);
            if (myPQueue.size()>k){                
                speedSum -= myPQueue.top();
                myPQueue.pop();
            }
            
            maxPerf = max(maxPerf, currEf * speedSum);
        }
        return maxPerf % 1000000007;
    }
};