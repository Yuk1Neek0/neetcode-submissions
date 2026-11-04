class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> minheap;

        for(auto const &num : nums){

            if(minheap.size() < k){

                minheap.push(num);
                continue;

            }
            else 
            if(num > minheap.top()){

                minheap.pop();
                minheap.push(num);

            }

        }
        return minheap.top();
    }
};
