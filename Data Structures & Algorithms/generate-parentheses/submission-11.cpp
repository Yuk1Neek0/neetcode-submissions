class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<char> Parentheses = {'(',')'};
        vector<string> res;
        string s;
        backtracking(n,0,0,s,res,Parentheses);
        return res;

    }

    void backtracking(int n, int l, int r, string &s,vector<string> &res, vector<char> &Parentheses){

        if(l > n || r > l) return;
        if(s.length() == n*2){

            res.push_back(s);
            return;

        }

        for(int i = 0; i < 2; i ++){
            
            char c = Parentheses[i];
            s.push_back(c);
            if(c == '(') l ++;
            else r ++;
            backtracking(n,l,r,s,res,Parentheses);

            s.pop_back();
            if(c == '(') l --;
            else r --;

        }

    }
};
