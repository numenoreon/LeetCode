class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *tempA=headA, *tempB=headB;
        
        while(tempA){
            while(tempB){
                if(tempA==tempB)
                    return tempA;
                tempB=tempB->next;
            }
            tempB=headB;
            tempA=tempA->next;
        }
        
        return nullptr;
    }
};