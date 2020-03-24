class Solution {
    public:
        int maxDistToClosest(vector <int> &seats) {
            const int N=seats.size();
            vector <int> seatsTaken;
            //seatsTaken.reserve(N);
            
            for(int i=0; i<seats.size();++i)
                if(seats[i]==1)
                    seatsTaken.push_back(i);
            
            const int M =seatsTaken.size();
            int totalMax=0;
            
            if(M==1){
                return totalMax=max( N-seatsTaken[0]-1,seatsTaken[0]);   
            }
            
            totalMax=max(totalMax,seatsTaken[0]);
            totalMax=max(totalMax,N-seatsTaken[M-1]-1);
            
            for(int i=1; i<=M-1; ++i){
                    totalMax=max(totalMax, (seatsTaken[i]-seatsTaken[i-1])/2);
                if(i+1<M)
                    totalMax=max(totalMax, (seatsTaken[i+1]-seatsTaken[i])/2);
            }
            return totalMax;
        }
};