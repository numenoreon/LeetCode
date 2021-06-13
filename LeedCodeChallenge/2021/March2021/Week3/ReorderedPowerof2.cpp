class Solution {
public:
    void fillVector(vector <string> &power2){
        long int number = 1;
        for(int i=0; i<32; ++i){
            power2[i]=to_string(number);
            sort(power2[i].begin(), power2[i].end());
            number*=2;
        }
    }
    
    bool reorderedPowerOf2(int N) {
        vector <string> power2(32,"");
        fillVector(power2);
        
        string probe = to_string(N);
        sort(probe.begin(), probe.end());
        
        auto it = find(power2.begin(), power2.end(), probe);  
        return it==power2.end() ? false : true;
    }
    
};
