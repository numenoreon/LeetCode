class Solution {
public:
    
    int decode(string &data, int start){
        if(start==0)
            return 1;
        
        int len=data.length()-start;
        
        if(data[len]=='0')
            return 0;
        
        if(start>=2 && ((data[len]-'0'<=2 && data[len+1]-'0'<=6) || (data[len]-'0'<2))){
            return decode(data,start-1) + decode(data,start-2);   
        }
        else{
        return decode(data,start-1);
        }
    }
    
    int numDecodings(string s) {
        return decode(s,s.length());
    }
};