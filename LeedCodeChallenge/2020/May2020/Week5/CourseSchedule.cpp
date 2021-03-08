class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& vec) {
        vector <int> quanityBefore (numCourses, 0);
        vector <vector <int> > coursesBefore (numCourses, vector <int> ());
        queue <int> myQueue;
       
        for(int i=0; i<vec.size(); ++i){
            ++quanityBefore[vec[i][0]];
            coursesBefore[vec[i][1]].push_back(vec[i][0]);
        }
       
        for(int i=0; i<quanityBefore.size(); ++i){
            if(quanityBefore[i] == 0)
                myQueue.push(i);
        }
        int counter=0;
        while(myQueue.size()){
            int temp = myQueue.front();
            myQueue.pop();
            ++counter;
            for(int i=0; i<coursesBefore[temp].size(); ++i){
                --quanityBefore[coursesBefore[temp][i]];
                if(quanityBefore[coursesBefore[temp][i]]==0)
                    myQueue.push(coursesBefore[temp][i]);
            }
        }

        return counter==numCourses ? true : false;
    }
};
