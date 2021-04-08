class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector <int> listValue;
        
        while(head){
            listValue.push_back(head->val);
            head=head->next;
        }
        
        bool truth = true;
        
        if(listValue.size()%2){
            int half=listValue.size()/2;
            int left=half-1, right=half+1;
            while(left>=0 && right<listValue.size()){
                if(listValue[left]!=listValue[right]){
                    truth=false;
                    break;
                }
                --left, ++right;
            }
        }
        else{
            int left=(listValue.size()-1)/2, right=listValue.size()/2;
            while(left>=0 && right<listValue.size()){
                cout << listValue[left] << " " << listValue[right] << endl;
                if(listValue[left]!=listValue[right]){
                    truth=false;
                    break;
                }
                --left, ++right;
            }
        }
            
        
        return truth;
    }
};