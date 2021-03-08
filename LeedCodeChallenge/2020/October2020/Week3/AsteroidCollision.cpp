class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector <int> results;
        results.reserve(asteroids.size());
        
        for(int i = 0; i<asteroids.size(); ++i){

            
            if(results.empty())
                results.push_back(asteroids[i]);
            else if((asteroids[i]>0 && results.back()>0) || (asteroids[i]<0 && results.back()<0)){
                results.push_back(asteroids[i]);
            }
            else if(asteroids[i]>0){
                results.push_back(asteroids[i]);
            }
            else if(asteroids[i]<0 && results.back()>0){
                bool alive=true;
                while(results.size() && results.back()>0){ 
                    if(abs(results.back())<abs(asteroids[i]))
                        results.pop_back();
                    else if(abs(results.back())==abs(asteroids[i])){
                        results.pop_back();
                        alive=false;
                        break;
                    }
                    else{
                        alive=false;
                        break;
                    }
                }
                
                if(alive)
                    results.push_back(asteroids[i]);
            }

        }
        
        return results;
    }
};