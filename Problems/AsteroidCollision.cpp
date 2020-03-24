class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.empty())
            return {};
        
        vector <int> myStack;
        myStack.reserve(asteroids.size());

        for(int i=0; i<asteroids.size(); ++i){
            if(myStack.empty()) 
                myStack.push_back(asteroids[i]);          
            
            else if(asteroids[i] < 0 && myStack.back() >0 ){  
                while(!myStack.empty() &&  myStack.back() >0  && myStack.back() < abs(asteroids[i]))
                        myStack.pop_back();
                
                if(myStack.empty() || myStack.back() < 0)
                    myStack.push_back(asteroids[i]);
                else if(-1*myStack.back()==asteroids[i])
                    myStack.pop_back();
            }

            else{
                myStack.push_back(asteroids[i]);
            }
            
        }

        return myStack;
    }
};