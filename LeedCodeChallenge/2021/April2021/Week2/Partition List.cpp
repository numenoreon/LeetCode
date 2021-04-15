class Solution {
public:
    ListNode* partition(ListNode* head, int target) {
        if(!head)
            return 0;
        
        vector <int> beforeTarget, afterTarget, accTarget;
        
        ListNode *temp = head;
        
        while(temp){
            if(temp->val<target)
                beforeTarget.push_back(temp->val);
            else if(temp->val >= target)
                afterTarget.push_back(temp->val);
                
            temp=temp->next;
        }
        
        temp=head;
        
        for(int i=0; i<beforeTarget.size(); ++i){
            temp->val=beforeTarget[i];
            temp=temp->next;
        }
        
        for(int i=0; i<afterTarget.size(); ++i){
            temp->val=afterTarget[i];
            temp=temp->next;
        }
        
        return head;
    }
};