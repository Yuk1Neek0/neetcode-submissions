class MedianFinder {
public: 
    priority_queue<int,vector<int>,less<>> leftside;
    priority_queue<int,vector<int>,greater<>> rightside;


    MedianFinder() {
        
    }
    
    void addNum(int num) {

        leftside.push(num);
        rightside.push(leftside.top());
        leftside.pop();

        if(rightside.size() > leftside.size()){

            leftside.push(rightside.top());
            rightside.pop();

        }

    }
    
    double findMedian() {
        if(leftside.size() == rightside.size()) return (leftside.top() + rightside.top()) / 2.0;
        else return leftside.top();
    }
};
