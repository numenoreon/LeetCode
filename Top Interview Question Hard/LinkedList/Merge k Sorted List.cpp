//We can merge k lists in proper order, depending on value, but we can also merge it without checking value and sort it after that;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int N = lists.size();
        if(N==1) return lists[0];
        
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        
        for(int i=0; i<N; i++){
            ListNode* List1=lists[i]; 
            while(List1){
                temp->next=new ListNode(List1->val);
                temp=temp->next;
                List1=List1->next;
            }
        }
        
        temp=newHead;
        newHead=newHead->next;
        delete temp;
        
        return sortList(newHead);
    }
    
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