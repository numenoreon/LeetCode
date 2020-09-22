class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        
        int posA = a.length()-1, posB = b.length()-1, carry=0, sum=0;
        
        while(posA >=0 || posB >=0){
            
            sum=carry;
            
            if(posA>=0){
                sum +=  a[posA] -'0';
                --posA;
            }
            if(posB>=0){
                sum += b[posB]- '0';
                --posB;
            }
            
            carry = sum>1 ? 1 : 0;
            sum=sum%2;
            result+=to_string(sum);
        }
        
        
        if(carry)
            result+='1';
        
        reverse(result.begin(), result.end());
        return result;
    }
};