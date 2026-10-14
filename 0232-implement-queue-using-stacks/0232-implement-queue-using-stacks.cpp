class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;
public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    void transfer(){
        if (output.empty()){
            while (!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
    }
    int pop() {
        if (empty()){
            throw std::runtime_error("Queue is empty");
        }
        transfer();
        int temp = output.top();
        output.pop();
        return temp;
    }
    
    int peek() {
        if (empty()){
            throw std::runtime_error("Queue is empty");
        }
        transfer();
        return output.top();
    }
    
    bool empty() {
        return output.empty() && input.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */