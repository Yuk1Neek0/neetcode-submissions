class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> res;
        dfs(s,res,n,0,0);
        return res;
    }
    void dfs(string &s, vector<string> & res, int n, int lnum, int rnum){

        if(rnum > lnum || lnum > n) return;
        if(lnum + rnum >= n * 2){

            if(lnum == rnum) res.push_back(s);
            return;

        }
        s.push_back('(');
        dfs(s,res,n,lnum + 1, rnum);
        s.pop_back();
        s.push_back(')');
        dfs(s,res,n,lnum,rnum + 1);
        s.pop_back();

    }
};
