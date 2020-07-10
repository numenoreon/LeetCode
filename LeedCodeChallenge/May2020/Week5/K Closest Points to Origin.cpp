class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        auto comp = [](vector <int> &a, vector <int> &b){
            return a[0]*a[0]+a[1]*a[1]>b[0]*b[0]+b[1]*b[1];
        };
        
        std::priority_queue<vector <int>, std::vector<vector<int>>, decltype(comp)> myQueue(comp);
            
        for(int i=0; i<points.size(); ++i){
        	myQueue.push(points[i]);
        }
        vector < vector <int>> results (K, vector <int>());
        for(int i=0; i<K; ++i){
            results[i]=myQueue.top();
            myQueue.pop();
        }
        
        return results;
    }
};