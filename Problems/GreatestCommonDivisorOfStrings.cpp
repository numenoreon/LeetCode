class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        if(str2.length() < str1.length()){
            string temp = str1;
            str1=str2;
            str2=temp;
        }
        
        int length = str1.length(), length2 = str2.length();
        
        string probe1, probe2, result="";
        
        for(int i=0; i<length; ++i){
            probe1+=str1[i];
            probe2=probe1;
            if(length%probe1.length() || length2%probe1.length()) // eliminate obvious case
                continue;
            while(probe2.length()<length)
                probe2+=probe1;
            
            if(probe2==str1){
                while(probe2.length()<length2)
                    probe2+=probe1;
                if(probe2==str2)
                    if(result.length()<probe1.length())
                        result=probe1;
            }
        }
        
        return result;
        
    }
};