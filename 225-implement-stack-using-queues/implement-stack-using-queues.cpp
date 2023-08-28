// Using 2 Queues Approach
// class MyStack {
// public:
//     MyStack() {
//     }
//     queue<int> queue1;
//     queue<int> queue2;

//     void push(int x) {
//         queue2.push(x); //first push new element to queue 2
//         while(!queue1.empty()) 
//         { // add all elements in queue1 to queue2
//             queue2.push(queue1.front());
//             queue1.pop();
//         }
//         //swap all elements back to queue 1
//         while(!queue2.empty())
//         {
//             queue1.push(queue2.front());
//             queue2.pop();
//         }
//     }
    
//     int pop() {
//         int temp = queue1.front();
//         queue1.pop();
//         return temp;
//     }
    
//     int top() {
//         return queue1.front();
//     }
    
//     bool empty() {
//         return queue1.empty();
//     }
// };

// class MyStack {
// public:
//     //optimised using one queue
//     MyStack() {
//     }
//     queue<int> ourQueue;

//     void push(int x) {
//         ourQueue.push(x);
//         for(int i = 0;i < ourQueue.size()-1; i++)
//         {
//             ourQueue.push(ourQueue.front());
//             ourQueue.pop();
//         }
//     }
    
//     int pop() {
//         int temp = ourQueue.front();
//         ourQueue.pop();
//         return temp;
//     }
    
//     int top() {
//         return ourQueue.front();
//     }
    
//     bool empty() {
//         return ourQueue.empty();
//     }
// };

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};




/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */