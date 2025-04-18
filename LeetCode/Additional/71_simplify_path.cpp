class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string>st; string temp = "";
        for(int i = 0;i < n;i++) {
            if(path[i] == '/') continue;
            while(i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if(temp == ".") { temp = ""; continue; }
            else if(temp == "..") {
                if(!st.empty()) st.pop();
                temp = "";
            }
            else {
                st.push(temp);
                temp = "";
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans.size() == 0) ans = "/";
        return ans;
    }
};
