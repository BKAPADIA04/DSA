class Solution {
public:
    

    void check(string &pattern,int pattern_index,string &temp,string &answer,vector<int>&visited) {
        if(pattern_index == pattern.size()) {
            if(temp < answer) answer = temp;
            // cout << answer << endl;
            return;
        }

        

        for(int i = 1;i <= 9;i++) {
            int n = temp.size();
            char ch = temp[n-1];
            int digit = ch - '0';
            if(pattern[pattern_index] == 'I') {
                if(i <= digit || visited[i]) continue;
            }
            else if(pattern[pattern_index] == 'D') {
                if(i >= digit || visited[i]) continue;
            }

            if(!visited[i]) {
                visited[i] = 1;
                char ch = i + '0';
                temp.push_back(ch);
                check(pattern,pattern_index+1,temp,answer,visited);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }

    string smallestNumber(string pattern) {
        int n = pattern.size();
        
        string temp = "";
        string answer = "99999999";
        
        for(int i = 1;i <= 9;i++) {
            vector<int>visited(10,0);
            visited[i] = 1;
            char ch = i + '0';
            temp.push_back(ch);
            check(pattern,0,temp,answer,visited);
            temp.pop_back();
            visited[i] = 0;
        }
        return answer;
    }
};

// Stack - O(n)
/*
class Solution {
public:
    string smallestNumber(string pattern) {
        string result;
        stack<int> numStack;

        // Iterate through the pattern
        for (int index = 0; index <= pattern.size(); index++) {
            // Push the next number onto the stack
            numStack.push(index + 1);

            // If 'I' is encountered or we reach the end, pop all stack elements
            if (index == pattern.size() || pattern[index] == 'I') {
                while (!numStack.empty()) {
                    result += to_string(numStack.top());
                    numStack.pop();
                }
            }
        }

        return result;
    }
};*/
