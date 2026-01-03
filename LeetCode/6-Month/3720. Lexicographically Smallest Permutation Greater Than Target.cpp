class Solution {
public:

    string answer;

    bool check(vector<char>&path, vector<int>&freq, string &target, bool flag) {
        int n = target.size();
        if(!answer.empty())return true;
        if(path.size() == n) {
            if(flag){
                answer=string(path.begin(),path.end());
                return true;
            }
            return false;
        }

        int i=path.size();
        for(int c = 0; c < 26;c++) {
            if(freq[c]==0)continue;
            if(!flag && c +'a'< target[i]) continue;

            path.push_back(c+'a');
            freq[c]--;

            bool newbig=flag ||(c+'a'>target[i]);

            if(check(path,freq,target,newbig))return true;

            path.pop_back();
            freq[c]++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int>freq(26);
        for(int i = 0;i < s.size();i++) freq[s[i] - 'a']++;

        if(accumulate(freq.begin(),freq.end(),0) <= 0) return "";

        answer = "";
        vector<char>path;
        check(path,freq,target,false);
        return answer;
        
    }
};
