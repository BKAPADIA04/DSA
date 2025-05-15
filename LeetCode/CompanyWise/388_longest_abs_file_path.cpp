class Solution {
public:
    int lengthLongestPath(string input) {
        int answer = 0;
        int n = input.size();
        stack<int>pathLength;
        stringstream ss(input);
        string word;

        while(getline(ss,word,'\n')) {
            int depth = 0;
            while(word[depth] == '\t') depth++;

            while(pathLength.size() > depth) pathLength.pop();
            string name = word.substr(depth);
            int length = (pathLength.empty() ? 0 : pathLength.top()) + name.size() + (pathLength.empty() ? 0 : 1);

            if(name.find('.') != string::npos) {
                answer = max(answer, length);
            }
            else {
                pathLength.push(length);
            }
        }
        return answer;

    }
};
