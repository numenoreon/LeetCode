class Solution {
public:
    Solution(ListNode* head) {
        srand(time(NULL));
        ListNode *temp=head;
        while(temp){
            data.push_back(temp->val);
            temp=temp->next;
        }
    }
    int getRandom() {
        int number = rand()%data.size();
        cout << number << " ";
        return data[number];
    }
private:
    vector <int> data;
};