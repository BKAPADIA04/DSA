class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        // vector<int>answer; int start = 0; int maxi = 0;
        // for(int i = 0;i < n;i++) {
        //     char ch = s[i];
        //     for(int j = i;j < n;j++) {
        //         if(s[j] == ch) maxi = max(maxi,j);
        //     }
        //     if(maxi == i) {
        //         answer.push_back(maxi - start + 1);
        //         start = i + 1;
        //         maxi = 0;
        //     }
        // }
        // return answer;

        vector<int>firstOccurence(26,-1); vector<int>lastOccurence(26,-1);
        for(int i = 0;i < n;i++) {
            if(firstOccurence[s[i] - 'a'] == -1) firstOccurence[s[i] - 'a'] = i;
            lastOccurence[s[i] - 'a'] = i;
        } 
        vector<int>answer; int start = 0; int maxi = 0;
        for(int i = 0;i < n;i++) {
            char ch = s[i];
            maxi = max(maxi,lastOccurence[ch - 'a']);
            if(maxi == i) {
                answer.push_back(maxi - start + 1);
                start = i + 1;
                maxi = 0;
            }
        }
        return answer;
    }
};
