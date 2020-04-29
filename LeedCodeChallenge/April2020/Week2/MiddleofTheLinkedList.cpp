class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int counter=0;
        while(temp){
            temp=temp->next;
            counter++;
        }
        counter/=2;
        temp=head;
        while(counter--){
            temp=temp->next;
        }
        
        return temp;
    }
};