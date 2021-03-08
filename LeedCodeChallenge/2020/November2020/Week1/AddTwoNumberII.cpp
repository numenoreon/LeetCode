class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector <int> list1, list2, merge;
        
        while(l1 && l2){
            list1.push_back(l1->val);
            list2.push_back(l2->val);
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1){
            list1.push_back(l1->val);
            l1=l1->next;
        }
        
        while(l2){
            list2.push_back(l2->val);
            l2=l2->next;
        }
        
        int length1=list1.size()-1, length2=list2.size()-1;

        while(length1>=0 && length2>=0){
            merge.push_back(list1[length1--]+list2[length2--]);
        }
        
        while(length1 >= 0){
            merge.push_back(list1[length1--]);
        }
        
        while(length2 >= 0){
            merge.push_back(list2[length2--]);
        }
        
        for(int i=0; i<merge.size()-1; ++i){
            if(merge[i]>=10){
                merge[i]-=10;
                ++merge[i+1];
            }
        }
        
        if(merge[merge.size()-1]>=10){
            merge[merge.size()-1]-=10;
            merge.push_back(1);
        }
        
        int i=merge.size()-1;
        
        ListNode *head = new ListNode(merge[i--]), *tempHead=head;
        
        while(i>=0){
            tempHead->next= new ListNode(merge[i--]);
            tempHead=tempHead->next;
        }
        
        return head;
    }
};