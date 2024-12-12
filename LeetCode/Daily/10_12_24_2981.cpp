class Solution {
public:

    void print(map<string,int>m) {
        for(auto it:m) {
            cout << it.first << " " << it.second << endl;
        }
    }

    int maximumLength(string s) {
        int n = s.size();
        map<string,int>m;
        string answer = ""; int maxi_size = 0; int j = 0; string temp = "";
        
        for(int i = 0;i < n;i++) {
            if(s[i] != s[j]) {
                string tempo = "";
                for(int k = j; k < j + temp.size();k++) {
                    tempo += s[k];
                    m[tempo] += temp.size() + j - k;
                    if(m[tempo] >= 3 && tempo.size() >= maxi_size) {
                        answer = tempo;
                        maxi_size = tempo.size();
                    }
                }
                temp = s[i];
                j = i;
            }
            else {
                temp += s[i];
            }
        }
        string tempo = "";
        for(int k = j; k < j + temp.size();k++) {
            tempo += s[k];
            m[tempo] += temp.size() + j - k;
            if(m[tempo] >= 3 && tempo.size() >= maxi_size) {
                answer = tempo;
                maxi_size = tempo.size();
            }
        }
        print(m);
        return maxi_size == 0 ? -1 : maxi_size;
    }
};