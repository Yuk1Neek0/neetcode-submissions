class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> degree(26,-1);

        for(string &s : words){

            for(char &c : s){

                degree[c - 'a'] = 0;

            }

        }
        unordered_map<int,vector<int>> dict;
        for(int i = 0; i < words.size() - 1; i ++){

            int j = 0, k = 0;
            bool is_find = false;
            while(j < words[i].size() && k < words[i + 1].size()){

                if(words[i][j] != words[i + 1][k]){

                    is_find = true;
                    dict[words[i][j] - 'a'].push_back(words[i + 1][k] - 'a');
                    degree[words[i + 1][k] - 'a'] ++;
                    break;
                }
                j ++;
                k ++;

            }
            if(!is_find && words[i + 1].size() < words[i].size()) return "";

        }
        string res = "";
        queue<int> que;
        for(int i = 0; i < 26; i++)
            if(degree[i] == 0) que.push(i);

        while(!que.empty()){

            int i  = que.front();
            que.pop();
            char c = i + 'a';
            res.push_back(c);

            for(int j = 0; j < dict[i].size(); j ++){

                degree[dict[i][j]] --;
                if(degree[dict[i][j]] == 0) que.push(dict[i][j]); 

            }

        }
        for(int i  = 0; i < 26; i ++){

            if(degree[i] != -1 && degree[i] != 0) return "";

        }
        return res;
    }
};
