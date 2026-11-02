class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<>> minheap;
    priority_queue<int,vector<int>,less<>> maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();

        if(minheap.size() > maxheap.size()){

            maxheap.push(minheap.top());
            minheap.pop();

        }
    
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size())

        return (minheap.top() + maxheap.top()) / 2.0;
        else return maxheap.top();
    }
};
