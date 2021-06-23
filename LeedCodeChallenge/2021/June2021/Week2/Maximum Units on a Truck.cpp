class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
    struct comp{
        bool operator()(vector <int> &a, vector <int> &b){
            if(a[1]==b[1])
                return a[0]>b[0];
            return a[1]<b[1];
        }
    };
        
    priority_queue < vector <int> , vector < vector <int> >, comp > pQ;
    
    for(auto &box : boxTypes)
        pQ.push({box[0], box[1]});
        
    int counter = 0;
    
    while(pQ.size() && truckSize){
        auto temp = pQ.top();
        if(truckSize<temp[0]){
            temp[0]=truckSize;
        }
        truckSize-=temp[0];
        pQ.pop();
        counter+=temp[0]*temp[1];
    }
        
    return counter;

    }
};
