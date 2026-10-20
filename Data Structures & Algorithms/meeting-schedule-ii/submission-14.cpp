/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        if(intervals.size() <= 1) return intervals.size();
        sort(intervals.begin(),intervals.end(),[](const Interval &interval1, const Interval &interval2){return interval1.start < interval2.start;});

        priority_queue<int,vector<int>,greater<>> que;

        que.push(intervals[0].end);

        for(int i = 1; i < intervals.size(); i++){

            int minend = que.top();

            if(intervals[i].start < minend)    que.push(intervals[i].end);
            else{

                que.pop();
                que.push(intervals[i].end);

            }

        }

        return que.size();

    }
};
