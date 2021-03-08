class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        for(auto &i : version1)
            if(i=='.')
                i=' ';
        for(auto &i : version2)
            if(i=='.')
                i=' ';
        
        //int result=0;
        
        //cout << version1 << " " << version2 << endl;
        
        stringstream ss1(version1), ss2(version2);
        
        int one, two;
        while(ss1.good() && ss2.good()){
            ss1 >> one;
            ss2 >> two;
            if(one>two)
                return 1;
            else if(two > one)
                return -1;
        }
        
        if(ss1.good() && !ss2.good()){
            while(ss1.good()){
                ss1 >> one;
                if(one!=0)
                    return 1;
            }
        }
        else if(!ss1.good() && ss2.good()){
            while(ss2.good()){
                ss2 >> one;
                if(one!=0)
                    return -1;
            }
        }
        
        return 0;
    }
};