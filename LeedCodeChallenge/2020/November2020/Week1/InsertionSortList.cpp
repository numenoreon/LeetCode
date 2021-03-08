class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return head;
        
        ListNode * newHead = new ListNode(head->val);                                  
        ListNode * tempOld = head->next, *tempNew = nullptr;
        
        while(tempOld){
            if(tempOld->val <= newHead->val){
                tempNew = new ListNode (tempOld->val);
                tempNew->next = newHead;
                newHead=tempNew;
                tempOld=tempOld->next;
                continue;
            }
            
            tempNew=newHead;
            while(tempNew->next && tempNew->next->val < tempOld->val ){
                tempNew=tempNew->next;
            }
            
            ListNode *tempNode = new ListNode(tempOld->val);
            tempNode->next=tempNew->next;
            tempNew->next=tempNode;
            tempOld=tempOld->next;
        }        
                                          
        return newHead;
    }
};