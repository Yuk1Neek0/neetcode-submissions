class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0 ) return {};
        vector<vector<char>> phone = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

        vector<string> res;
        string s;
        backtracking(digits,0,res,s,phone);
        return res;
    }

    void backtracking(string &digits, int n, vector<string> &res, string &s, vector<vector<char>> &phone){

        if(n > digits.length()) return;
        if(n == digits.length()){

            res.push_back(s);
            return;
        
        }

        for(int i = 0; i < phone[digits[n] - '2'].size(); i++){

            s.push_back(phone[digits[n] - '2'][i]);

            backtracking(digits,n+1,res,s,phone);

            s.pop_back();
        }

    }
};
