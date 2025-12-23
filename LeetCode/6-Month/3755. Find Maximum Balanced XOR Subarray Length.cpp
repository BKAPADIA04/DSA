class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>umap;
        int answer = INT_MAX;
        for(int i = n-1;i >= 0;i--) {
            int num = nums[i];
            int tempo = num;
            while(tempo % 10 == 0) tempo /= 10;
            string temp = to_string(tempo);
            reverse(temp.begin(),temp.end());
            int anotherNum = stoi(temp);
            if(umap.find(anotherNum) != umap.end()) {
                answer = min(answer, umap[anotherNum] - i);
            }
            umap[num] = i;
        }

        answer = (answer == INT_MAX) ? -1 : answer;
        return answer;
    }
};
