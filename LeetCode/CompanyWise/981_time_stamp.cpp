class TimeMap {
public:

    map<string,vector<pair<int,string>>>mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string temp = string(101,'z');
        pair<int,string>p = {timestamp,temp};
        cout << mp[key].size() << " ";
        int it = upper_bound(mp[key].begin(),mp[key].end(),p) - mp[key].begin() - 1;
        if(it < 0) return "";
        return mp[key][it].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
