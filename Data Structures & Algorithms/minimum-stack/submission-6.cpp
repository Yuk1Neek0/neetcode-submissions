class MinStack {
public:
    stack<int> minst;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(minst.empty() || val <= minst.top()) minst.push(val);
        st.push(val);

    }
    
    void pop() {
        int val = st.top();
        st.pop();

        if(val == minst.top()) minst.pop();
    }
    
    int top() {
        
        return st.top();

    }
    
    int getMin() {
        return minst.top();
    }
};
