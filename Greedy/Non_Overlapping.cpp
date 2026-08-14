//Non Overlapping Interval

bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
    }

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int lastSeen = intervals[0][1];
        int count = 1;

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] >= lastSeen) {
                count++;
                // iske baad aage badhega i therefore
                lastSeen = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};
