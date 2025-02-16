class Solution {
public:

    void print(vector<int>nums) {
        for(auto it:nums) cout << it << " ";
        cout << endl;
    }

    bool generate(vector<int>&answer,vector<int>&visited,int num,int index) {
        int n = answer.size();
        if(index == n) return true;
        if(answer[index] != 0) return generate(answer,visited,num,index+1);

        for(int i = num;i >= 1;i--) {
            int nextIndex = (i == 1) ? index : index + i;
            if(visited[i] || (i > 1 && nextIndex >= n) || answer[nextIndex] != 0) continue;

            answer[index] = answer[nextIndex] = i;
            visited[i] = 1;

            if(generate(answer,visited,num,index+1)) return true;

            answer[index] = answer[nextIndex] = 0;
            visited[i] = 0;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int>answer(2 * n - 1,0); vector<int>visited(n+1,0);
        int index = 0;
        generate(answer,visited,n,0);
        return answer;
    }
};
