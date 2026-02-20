class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.size();
        int count = 0; 
        vector<string>answer; 
        int j = 0; // j...i
        for(int i = 0;i < n;i++) {
            count += ((s[i] == '1') ? 1 : -1);
            if(count == 0) {
                answer.push_back('1' + makeLargestSpecial(s.substr(j+1, i - j - 1)) + '0');
                j = i + 1;
            }
        }

        sort(answer.rbegin(), answer.rend());
        string res;
        for(auto it : answer) res += it;
        return res;
    }
};
