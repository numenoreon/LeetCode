class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        for(ListNode* i=head; i!=nullptr; i=i->next){
            for(ListNode* j = i->next; j!=nullptr;j=j->next){
                if(j->val < i->val){
                    int temp = j->val;
                    j->val = i->val;
                    i->val = temp;
                }
            }     
        }
        
    return head;
    }
};