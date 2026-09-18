class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        string subres;
        backtracking(subres,res,n,0,0);
        return res;

    }

    void backtracking(string &subres, vector<string> &res, int &n, int ln, int rn){

        if(ln > n || rn > ln) return;
        if(subres.size() == n * 2){

            res.push_back(subres);
            return;

        }

        char par[2] = {'(' , ')'};
        for(int i = 0; i < 2; i++){

            subres.push_back(par[i]);
            if(i == 0) backtracking(subres,res,n,ln + 1,rn);
            else backtracking(subres,res,n,ln,rn + 1);
            subres.pop_back();
 
        }

    }
};
