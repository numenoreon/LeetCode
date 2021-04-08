class MyCircularQueue {
private:
    vector<int> q;
    int h, t;
    int cap, cnt;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        cap = k;
        if (!cap)
            return;
        q = vector<int>(cap);
        h = 0; t = 0;
        cnt = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (cnt == cap)
            return false;
        cnt++;
        h = (h+1)%cap;
        q[h] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!cnt)
            return false;
        cnt--;
        t = (t+1)%cap;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (cnt == 0)
            return -1;
        return q[(t+1)%cap];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (cnt == 0)
            return -1;
        return q[h];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (cnt == 0);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (cnt == cap);
    }
};