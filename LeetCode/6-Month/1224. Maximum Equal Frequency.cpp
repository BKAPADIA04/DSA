class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        unordered_map<int,int>freqCount; // freq, no. of elements
        unordered_map<int,int>numFreq; // num, freq

        int answer = 1; 
        
        for(int i = 0;i < n;i++) {
            numFreq[nums[i]]++;
            freqCount[numFreq[nums[i]]]++;

            if((numFreq[nums[i]] * freqCount[numFreq[nums[i]]]) == (i + 1)) {
                if(i + 1 < n) answer = max(answer, i + 2);
            }

            if((numFreq[nums[i]] * freqCount[numFreq[nums[i]]]) == (i)) {
                answer = max(answer, i + 1);
            }
        }

        return answer;
    }
};
