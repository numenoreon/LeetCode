class Solution {
public:
    string simplifyPath(string path) {
        string result="/";
        string temp="";
        stringstream ss(path);
        
        while(getline(ss, temp, '/')){
            
            if(temp=="." || temp=="/" || temp.empty())
                continue;
            if(temp==".."){
                if(result.size()==1)
                    continue;
                result.pop_back();
                while(result.size()>1 && result.back()!='/')
                    result.pop_back();
            }    
            else{
                result+=(temp+'/');
            }
        }
        
        if(result.size()>1 && result.back()=='/')
            result.pop_back();
        return result;
    }
};