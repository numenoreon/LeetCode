class Node{
public:
    Node* prev;
    int val;
    
    Node(int x) : val(x) {}
};


class MinStack {    
    Node *up;   
public:
    MinStack() {
        up = nullptr;
    }
    
    ~MinStack(){
        while(up){
            Node* temp = up;
            up=up->prev;
            delete temp;
        }
    }
    
    void push(int x) {
        if(!up){
            up = new Node(x);
            up->prev=nullptr;
        }
        else{
            Node *temp = new Node(x);
            temp->prev=up;
            up=temp;
        }
    }
    
    void pop() {
        if(up){
        Node* temp = up;
        up=up->prev;
        delete temp;
        }
    }
    
    int top() {
        if(up)
            return up->val;
        return 0;
    }
    
    int getMin() {
        if(up){
        Node *temp=up;
        int min=INT_MAX;
        while(temp){
            if(temp->val < min)
                min=temp->val;
            temp=temp->prev;
            }
        return min;
        }
        return 0;
    }
};