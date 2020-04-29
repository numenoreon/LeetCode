class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle == "")
            return 0;
        auto it = haystack.find(needle);
        if (it == std::string::npos)
            return -1;
        return it;
    
    }
};

_______________________________________________________________________________

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int N=haystack.size(), M=needle.size();
        string temp = "";
        if(M==0)
            return 0;
        if(N==0 || M>N)
            return -1;
        
        for(int i=0; N-i>=M; ++i){
            if(haystack[i]==needle[0]){
                temp=haystack.substr(i,M);
                if(temp==needle)
                    return i;
            }
        }
        
        return -1;
    }
};