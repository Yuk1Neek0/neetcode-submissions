class KthLargest {
public:

    int k;
    priority_queue<int,vector<int>,greater<int>> minheap;
    KthLargest(int k, vector<int>& nums) {
        
        this -> k = k;
        for(int n : nums) {

            if(minheap.size() < k) minheap.push(n);
            else if(n > minheap.top()){

                minheap.pop();
                minheap.push(n);

            }

        }

    }
    
    int add(int val) {
        
        if(minheap.size() < k) minheap.push(val);
            else if(val > minheap.top()){

                minheap.pop();
                minheap.push(val);

            }

        return minheap.top();
    }
};
