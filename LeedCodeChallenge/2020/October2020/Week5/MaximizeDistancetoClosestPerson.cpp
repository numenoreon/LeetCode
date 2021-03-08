class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int N=seats.size();
        int counter=1, result=1;
        
        for(int i=0; i<N; i++){
            if(i==0 && seats[0]==0){
                for(int j=i+1; j<seats.size(); ++j){
                    if(seats[j]==0){
                        ++counter;
                    }
                    else{
                        result=max(result, counter);
                        counter=1;
                        break;
                    }
                }
            }
            else if(i==N-1 && seats[N-1]==0){
                for(int j=i-1; j>=0; --j){
                    if(seats[j]==0){
                        ++counter;
                    }
                    else{
                        result=max(result, counter);
                        counter=1;
                        break;
                    }
                }
            }
            else if(seats[i]==0){
                int left=i-1, right=i+1;
                
                while(left >=0 || right <N){
                    if(left>=0 && right <N){
                        if(seats[left]==0 && seats[right]==0){
                            ++counter;
                            --left;
                            ++right;
                        }
                        else{
                            break;
                        }
                    }
                    else if(left>=0){
                        if(seats[left]==0){
                            --left;
                            ++counter;
                        }
                        else{
                            break;
                        }
                    }
                    else if(right<N){
                        if(seats[right]==0){
                            ++right;
                            ++counter;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                
                result=max(result, counter);
                counter=1;
            }
        }
        
        
        return result;
    }
};