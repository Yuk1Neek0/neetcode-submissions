class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> lowtemp;
        stack<int> date;
        vector<int> res(temperatures.size(),0);

        lowtemp.push(temperatures[0]);
        date.push(0);
        res[0] = 0;

        for(int i = 1; i < temperatures.size(); i ++){

            while(!lowtemp.empty() && temperatures[i] > lowtemp.top()){

                int day = date.top();
                date.pop();               
                lowtemp.pop();

                res[day] = i - day;

            }

            lowtemp.push(temperatures[i]);
            date.push(i);

        }

        return res;
        
    }
};
