class MinStack {
    stack<int> main;
    stack<int> minn;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(minn.empty() || minn.top()>=val){
            minn.push(val);
        }
        main.push(val);
    }
    
    void pop() {
        if(minn.top()==main.top()){
            minn.pop();
        }
        main.pop();
    }
    
    int top() {
        if(!main.empty()){
           return main.top();
        }
        else return NULL;
    }
    
    int getMin() {
        if(!minn.empty()){
           return minn.top();
        }
        else return NULL;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */