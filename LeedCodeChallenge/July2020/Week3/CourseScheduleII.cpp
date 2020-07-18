class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector <int> requiredCounter (numCourses, 0);
        vector <vector <int>> coursesUnlock (numCourses, vector <int> {});
        
        for(int i=0; i<prerequisites.size(); ++i){
            ++requiredCounter[prerequisites[i][0]];
            coursesUnlock[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue <int> myQueue;
        
        for(int i=0; i<requiredCounter.size(); ++i){
            if(requiredCounter[i]==0)
                myQueue.push(i);
        }
        
        //if(myQueue.empty())
        //    return {};
        vector <int> result {};
        int temp1=-1, temp2=-1;
        while(!myQueue.empty()){
            temp1=myQueue.front();
            myQueue.pop();
            while(!coursesUnlock[temp1].empty()){
                temp2=coursesUnlock[temp1].back();
                coursesUnlock[temp1].pop_back();
                if(--requiredCounter[temp2]==0)
                    myQueue.push(temp2);    
            }
            result.push_back(temp1);
        }
        
        //priority_queue <int, vector <int>, decltype(cmp)> myQueue(cmp);        
        
        if(result.size()!=numCourses)
            return {};
        return result;
    }
};