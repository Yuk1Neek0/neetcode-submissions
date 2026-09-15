class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> result;
       
        for(int i=0;i<strs.size();i++){
             int count[30]={0};
            for(int j=0;j<strs[i].length();j++){
                count[strs[i][j]-'a']++;
            }

            string key = to_string(count[0]);
            for(int i=1;i<26;i++){
                key += ','+to_string(count[i]);
            }

            result[key].push_back(strs[i]);
        }

        for(const auto &it : result){
            res.push_back(it.second);
        }
        return res;
    }
};
