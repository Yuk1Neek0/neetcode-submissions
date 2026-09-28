class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if(digits.length() == 0) return {};
        vector<vector<char>> phone = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

        vector<string> res;
        string s;
        dfs(digits,phone,res,s,0);
        return res;

    }

    void dfs(string &digits, vector<vector<char>> &phone, vector<string> &res, string &s, int n){

        if(n >= digits.length()){

            res.push_back(s);
            return;

        }

        for(int i = 0; i < phone[digits[n] - '2'].size(); i++){

            s.push_back(phone[digits[n] - '2'][i]);
            dfs(digits, phone, res, s, n + 1);
            s.pop_back();
        }

    }
};
