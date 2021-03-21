class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int counter=0;
        
        while(temp){
            ++counter;
            temp=temp->next;
        }
        
        int backK = counter - k;
        
        ListNode *nodeK=head;
        ListNode *nodeBK=head;
        
        while(--k){
            nodeK=nodeK->next;
        }
        
        while(backK--){
            nodeBK=nodeBK->next;
        }
        
        swap(nodeK->val, nodeBK->val);
        
        return head;   
    }
};