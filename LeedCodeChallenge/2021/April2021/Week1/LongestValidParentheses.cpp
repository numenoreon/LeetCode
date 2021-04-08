class Solution {
public:
    int longestValidParentheses(string s) {
        
        const int N = s.length();
        
        stack <int> myStack;
        int maxlen = 0, i = 0;
        
        for (i = 0; i < N; i++) {
            if (!myStack.empty() && s[myStack.top()] == '(' && s[i] == ')') {
                myStack.pop();
                maxlen = myStack.empty() ? max(maxlen, i+1) : max(maxlen, i-myStack.top());
            } else {
                myStack.push(i);
            }
        }
        
        return maxlen;
    }
};