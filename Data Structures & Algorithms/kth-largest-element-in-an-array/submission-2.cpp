class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;

        for(int n : nums) {

            if(minheap.size() < k) minheap.push(n);
            else if( n > minheap.top()){

                minheap.pop();
                minheap.push(n);

            }

        }

        return minheap.top();

    }
};
