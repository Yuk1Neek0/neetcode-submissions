class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> res;

        for(int i = 0; i < nums.size(); i ++){

            while(!que.empty() && nums[i] >= nums[que.back()]) que.pop_back();
            que.push_back(i);
            if(que.front() <= i - k) que.pop_front();

            if(i >= k - 1) res.push_back(nums[que.front()]);
        }
        return res;
    }
};
