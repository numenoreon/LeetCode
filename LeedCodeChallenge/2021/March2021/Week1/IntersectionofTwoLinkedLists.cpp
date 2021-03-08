class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp, *temp2;
        int len1 , len2;
        
        len1 = 0 ;
        temp = headA;
        while(temp != NULL){
            len1++;
            temp = temp->next;
        }
        
        temp2 = headB;
        len2 = 0;
        while(temp2 != NULL){
            len2++;
            temp2= temp2->next;
        }
        int dif = abs(len2 - len1);
        temp = headA;
        temp2 = headB ;
        
        if(len2 > len1){
            while(dif--){
                temp2 = temp2->next;
            }    
        }else{
            while(dif--){
                temp = temp->next;
            }
        }
        
        while(temp != NULL){
            if(temp == temp2){
                return temp;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return NULL;
    }
};