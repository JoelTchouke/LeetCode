class MyCircularQueue {
private:
    int size;
    vector<int> queue;
    int head;
    int tail;
    bool full;
public:
    MyCircularQueue(int k) : size(k), queue(k), head(0), tail(0), full(false) {}
    
    bool enQueue(int value) {
        if(isFull()) return false;
        queue[head] = value;
        head = (head+1) % size;
        if (head == tail) this->full = true;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        this->full = false;
        tail = (tail + 1) % size;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        int val = queue[tail];
        return val;
    }
    
    int Rear() {
         if (isEmpty()) return -1;
        return queue[(head + size - 1) % size];
    }
    
    bool isEmpty() {
        return (head == tail && !this->full);
    }
    
    bool isFull() {
        return this->full;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */