class MyStack {
    queue<int> q1, q2;
    int curr_size;
public:
    MyStack() {
        curr_size = 0;
    }
    
    void push(int x) {
        curr_size++;

        q2.push(x);
        
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
 
        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    
    int pop() {
        if (q1.empty())
            return -1;
        
        int pp= q1.front();
         q1.pop();
        curr_size--;
        return pp;
    }
    
    int top() {
        if (q1.empty())
            return -1;
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
            return false;
    }
};