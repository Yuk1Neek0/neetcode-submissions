class MinStack {
private:

    long min;
    stack<long> st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(st.empty()){

            st.push(0);
            min = val;

        }else{

            st.push( val - min );
            if(val < min) min = val;

        }

    }
    
    void pop() {
        
        long n = st.top();

        if(n < 0){

            min = min - n;

        }

            st.pop();

    }
    
    int top(){
        
        long n = st.top();

        if(n > 0 ) return (int)(n + min);
        else return (int) min; 

    }
    
    int getMin() {
        
        return min;

    }
};
