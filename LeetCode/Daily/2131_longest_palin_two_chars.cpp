class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int answer = 0;
        map<pair<char,char>,int>mp;
        unordered_map<string,int>freq;
        for(int i = 0;i < n;i++) {
            string str = words[i];
            char ch1 = str[0]; char ch2 = str[1];
            if(ch1 == ch2) freq[str]++;
            pair<char,char>p = {ch2,ch1};
            if(mp.find(p) != mp.end()) {
                answer += 4;
                mp[p]--;
                if(mp[p] == 0) mp.erase(p);
            }
            else mp[{ch1,ch2}]++;
        }
        bool check = false;
        for(auto it : freq) {
            if(it.second & 1) check = true;
        }
        answer = answer + (check ? 2 : 0);
        return answer;
    }
};
