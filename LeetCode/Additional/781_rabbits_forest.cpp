class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int>freq;
        int ans = 0;
        for(int i = 0;i < n;i++) {
            freq[answers[i]]++;
        }

        for(auto it : freq) {
            int num = it.first;
            int count = it.second;

            int grps = (count + num) / (num + 1);
            //ceil = (a + b - 1)/b
            ans += grps * (num + 1);
        }
        return ans;
    }
};
