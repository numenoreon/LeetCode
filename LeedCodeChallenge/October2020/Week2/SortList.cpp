BUBBLE SORT

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		ListNode* iter = head;
        int tempVal=0;
		while(iter != nullptr) {
			ListNode* tempNode = iter->next;
			while (tempNode != nullptr) {
				if (iter->val > tempNode->val) {
					tempVal = iter->val;
					iter->val = tempNode->val;
                    tempNode->val = tempVal;
				}
                tempNode=tempNode->next;
			}
			iter = iter->next;
		}
        return head;
	}
};


___________________________________________________________________________________________________________________

TRICK SORT

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        multiset <int> elements;
        ListNode *tempNode = head;
        while(tempNode){
            elements.insert(tempNode->val);
            tempNode=tempNode->next;
        }
        tempNode=head;
        
        while(tempNode){
            tempNode->val=*elements.begin();
            elements.erase(elements.begin());
            tempNode=tempNode->next;
        }
        
        return head;
    }
};