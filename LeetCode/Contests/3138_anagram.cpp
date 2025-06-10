class Solution {
public:

    bool check(string &s, int mid) {
        vector<int>freq(26);
        int n = s.size();
        if(s.size() < mid) return false;
        if(s.size() % mid) return false;
        for(int i = 0;i < mid;i++) {
            freq[s[i] - 'a']++;
        }

        for(auto it : freq) cout << it << " " ;
        cout << endl;

        int counter = 0;
        vector<int>temp(26);
        for(int i = mid;i < n;i++) {
            temp[s[i] - 'a']++;
            counter++;
            if(counter % mid == 0) {
                if(mid == 3) {
                    for(auto it : temp) cout << it << " " ; cout << endl;
                }
                // for(auto it : temp) cout << it << " " ; cout << endl;
                for(int i = 0;i < 26;i++) {
                    if(temp[i] != freq[i]) return false;
                }
                counter = 0;
                for(int i = 0;i < 26;i++) temp[i] = 0;
            }
        }
        return true;
    }

    int minAnagramLength(string s) {
        int n = s.size();
        int low = 1;
        int high = n;
        int ans = high;
        for(int i = low;i <= high;i++) {
            if(check(s,i)) return i;
        }
        return n;
    }
};
