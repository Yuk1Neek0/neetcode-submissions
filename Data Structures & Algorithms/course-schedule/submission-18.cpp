class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> mapping;
        vector<int> in_degree(numCourses ,0);
        int finished = 0;

        for(auto const& n : prerequisites){

            in_degree[n[0]] ++;
            mapping[n[1]].push_back(n[0]);

        }


        queue<int> que;
        for(int i = 0; i < numCourses; i++){

            if(in_degree[i] == 0) que.push(i);

        }

        while(!que.empty()){

            int size = que.size();
            for(int i = 0; i < size; i++){

                int t = que.front();
                que.pop();
                for(int n : mapping[t]){

                    in_degree[n] --;
                    if(in_degree[n] == 0) que.push(n);

                }

                finished ++;

            }

        }

        if(finished != numCourses) return false;
        if(!que.empty()) return false;
        return true;

    }
};
