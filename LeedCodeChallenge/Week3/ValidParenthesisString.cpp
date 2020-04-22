class Solution {
public:
    bool checkValidString(string s) {
        stack <int> open, star;
      
        for(int i=0; i<s.length(); ++i){
            if(s[i]==')'){
                if(open.size())
                    open.pop();
                else if(star.size())
                    star.pop();
                else
                    return false;
            }
            else if(s[i]=='(')
                open.push(i);
            else
                star.push(i);
        }
        
        while(open.size() && star.size()){
            if(open.top() < star.top()){
                open.pop();
                star.pop();
            }
            else
                return false;
        }
        
        return open.empty();
    }
};