class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mapping;

        for(string s : strs){

            vector<int> nums(26,0);

            for(char c : s) nums[c - 'a'] ++;

            string key = "";
            for(int i = 0; i < 26; i ++){

                key += to_string(nums[i]);
                key += '*';

            }

            mapping[key].push_back(s);

        }

        vector<vector<string>> res;

        for(auto const& it : mapping){

            res.push_back(it . second);

        }

        return res;
    }
};
