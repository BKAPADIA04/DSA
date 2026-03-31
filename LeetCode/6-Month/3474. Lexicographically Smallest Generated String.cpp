class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string answer(n + m - 1, '?');
        vector<bool>visited(n + m - 1, false);
        for(int i = 0;i < n;i++) {
            if(str1[i] == 'T') {
                for(int j = 0;j < m;j++) {
                    if(answer[i+j] == '?' || answer[i+j] == str2[j]) {
                        answer[i+j] = str2[j];
                        visited[i+j] = true;
                    }
                    else return "";
                }
            }
        }

        for(int i = 0;i < n + m - 1;i++) {
            if(answer[i] == '?') {
                answer[i] = 'a';
            }
        }

        for(int i = 0;i < n;i++) {
            if(str1[i] == 'F') {
                bool flag = true;
                for(int j = 0;j < m;j++) {
                    if(answer[i + j] != str2[j]) {
                        flag = false;
                        break;
                    }
                }

                if(flag) {
                    bool flg = false;
                    for(int j = m-1;j >= 0;j--) {
                        int idx = i + j;
                        if(visited[idx]) continue;

                        for(char ch = 'a';ch <= 'b';ch++) {
                            if(ch != str2[j]) {
                                answer[idx] = ch;
                                flg = true;
                                break;
                            }
                        }

                        if(flg) break;
                    }

                    if(!flg) return "";
                } 
            }
        }
        return answer;
    }
};
