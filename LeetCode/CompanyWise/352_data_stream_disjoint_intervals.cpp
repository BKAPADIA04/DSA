class SummaryRanges {
public:

    map<int,pair<int,int>>intervals;

    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto next = intervals.upper_bound(value);
        auto previous = (next == intervals.begin()) ? intervals.end() : prev(next);

        if(previous != intervals.end() && next != intervals.end() && previous->second.second + 1 == value && next->second.first - 1 == value) {
            previous->second.second = next->second.second;
            intervals.erase(next);
        }
        else if(previous != intervals.end() && previous->second.second + 1 >= value) {
            previous->second.second = max(value,previous->second.second);
        }
        else if(next != intervals.end() && next->second.first - 1 == value) {
            intervals[value] = {value,next->second.second};
            intervals.erase(next);
        }
        else {
            intervals[value] = {value,value};
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>answer;
        for(auto it : intervals) {
            answer.push_back({it.second.first, it.second.second});
        }
        return answer;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
