class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> dict={

            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"

        };
        vector<string> res;
        string subres = "";

        dfs(digits,dict,res,subres,0);
        return res;
    }
    void dfs(string digits, vector<string> dict, vector<string> &res, string &subres, int n){

        if(n >= digits.size()){

            res.push_back(subres);
            return;

        }

        for(int i = 0; i < dict[digits[n] - '0' - 2].size(); i ++){

            subres.push_back(dict[digits[n] - '0' - 2][i]);
            dfs(digits,dict,res,subres,n + 1);
            subres.pop_back();

        }

    }
};
