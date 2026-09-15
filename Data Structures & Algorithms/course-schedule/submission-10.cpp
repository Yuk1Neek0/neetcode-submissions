class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        int finished = 0;
        queue<int> que;
        unordered_map<int,vector<int>> mapping;
        int in_degree[1000] = {0};
        for(int i = 0 ;i < prerequisites.size(); i++){

            mapping[prerequisites[i][1]] .push_back(prerequisites[i][0]);
            in_degree[prerequisites[i][0]] ++;

        }

        for(int i = 0; i < numCourses; i++){

            if(in_degree[i] ==0) que.push(i);

        }

        while(!que.empty()){

            int size = que.size();
            for(int i = 0; i < size; i++){

                for(int n : mapping[que.front()]){

                    in_degree[n] --;
                    if(in_degree[n] == 0) que.push(n);

                }
                que.pop();
                finished ++;

            }

        }

        if(numCourses != finished) return false;
        for(int n : in_degree){

            if(n != 0) return false;

        }
        return true;


    }
};
