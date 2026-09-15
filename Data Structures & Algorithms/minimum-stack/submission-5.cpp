class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {       
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty()) minst.push(val);
        else
        if(val <= minst.top()){

            minst.push(val);
            
        }
    }
    
    void pop() {

        int t = st.top();
        st.pop();
        if(!minst.empty() && t == minst.top()) minst.pop();

    }
    
    int top() {
        
        return st.top();

    }
    
    int getMin() {
        
        return minst.top();

    }
};
