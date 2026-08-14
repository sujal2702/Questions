//Merge Interval 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return intervals;

        vector<vector<int>> merge;
        
        sort(intervals.begin(), intervals.end());
        merge.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(merge.back()[1] < s)
            {
                merge.push_back({s,e});
            }
            else
            {
                merge.back()[1] = max(merge.back()[1], e);
            }
        }
        return merge;
    }
};

/*
pehle sort karo

phir 1st interval[i] push kar do

phir s and e assign karo

then check if already pushed ka ending[1th index] < next starting if true then push next{s,e}

else update the already pushed ka [1]th index with max( already pushed ka [1]th index , new e (next e))
*/
