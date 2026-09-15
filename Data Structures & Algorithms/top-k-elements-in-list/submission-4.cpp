class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<vector<int>> record(nums.size()+1);
        unordered_map<int,int> map;
        
        for(int i = 0; i < nums.size(); i++){

            map[nums[i]] ++;

        }

        for(const auto n : map){

            record[n.second].push_back(n.first);

        }

        vector<int> res;

        for(int i = record.size() - 1; i >=0 ; i--){

            if(res.size() >=k ) break;

            for(int j = 0; j< record[i].size(); j++){
                
                if(res.size() >=k ) break;
                res.push_back(record[i][j]);

            }

        }
        return res;
 
    }
};
