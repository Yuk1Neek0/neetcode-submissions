    class Solution {
    public:
        string foreignDictionary(vector<string>& words) {
            unordered_map<char,vector<char>> dict;
            vector<int> degree(26,-1);
            string res = "";
            if(words.size() == 1) return words[0];
            for(int i = 0; i < words.size(); i ++){

                for(char c : words[i]) degree[c - 'a'] = 0;

            }

            for(int i = 0; i < words.size() - 1; i ++){

                int index1 = 0, index2 = 0;
                bool is_valid = false;
                while(index1 < words[i].size() && index2 < words[i + 1].size()){

                    if(words[i][index1] != words[i + 1][index2]){

                        is_valid = true;
                        dict[words[i][index1]].push_back(words[i + 1][index2]);
                        degree[words[i + 1][index2] - 'a'] ++; 
                        break;

                    }
                    index1 ++;
                    index2 ++;

                }
                if(!is_valid && words[i].length() > words[i + 1].length()) return res;

            }

            queue<char> que;

            for(int i = 0; i < 26; i ++){

                char c = 'a' + i;
                if(degree[i] == 0) 
                que.push(c);

            }
            while(!que.empty()){

                char c = que.front();
                que.pop();
                res.push_back(c);
                if(dict.contains(c)){

                    for(int i = 0; i < dict[c].size(); i ++){

                        char cc = dict[c][i];
                        degree[cc - 'a'] --;
                        if(degree[cc - 'a'] == 0) que.push(cc);

                    }

                }

            }
            for(int i = 0 ; i < 26; i++) if(degree[i] != 0 && degree[i] != -1) return "";
            return res;

        }
    };
