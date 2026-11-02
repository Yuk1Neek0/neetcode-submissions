class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> que;
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++){

            while(!que.empty() &&nums[i] >= que.back().second){

                que.pop_back();

            }

            que.push_back({i,nums[i]});
            if(i - que.front().first >= k) que.pop_front();

            if(i >= k - 1) res.push_back(que.front().second);
            

        }
        return res;
    }
};
