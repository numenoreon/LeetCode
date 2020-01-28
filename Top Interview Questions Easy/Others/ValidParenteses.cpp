class Solution {
public:
    bool isValid(string s) {
        stack <char> pile;
        
        for(int i=0; i<s.length(); ++i){
            if(pile.empty() && (s[i]==']' || s[i]=='}' || s[i]==')'))
               return false;
            else if(s[i]=='}' && pile.top()!='{')
               return false;
            else if(s[i]==')' && pile.top()!='(')
               return false;
            else if(s[i]==']' && pile.top()!='[')
               return false;
            else if(s[i]=='}' && pile.top()=='{')
               pile.pop();
            else if(s[i]==')' && pile.top()=='(')
               pile.pop();
            else if(s[i]==']' && pile.top()=='[')
               pile.pop();
            else 
               pile.push(s[i]);
        }
               
        if(!pile.empty())
           return false;
               
        return true;
    }
};