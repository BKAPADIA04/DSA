class Solution {
public:

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>oddMap, evenMap;
        int oddMaxNum = 0; int oddMaxFreq = 0;
        int oddMaxSecond = 0; int oddMaxSecondFreq = 0;
        int oddIndices = 0; 

        int evenMaxNum = 0; int evenMaxFreq = 0;
        int evenMaxSecond = 0; int evenMaxSecondFreq = 0;
        int evenIndices = 0;

        for(int i = 0;i < n;i++) {
            if(i & 1) {
                oddMap[nums[i]]++;
                oddIndices++;
            }
            else {
                evenMap[nums[i]]++;
                evenIndices++;
            }
        }

        for(auto it = oddMap.begin(); it != oddMap.end(); it++) {
            int num = it->first; int count = it->second;
            if(count > oddMaxFreq) {
                oddMaxSecondFreq = oddMaxFreq;
                oddMaxSecond = oddMaxNum;

                oddMaxFreq = count;
                oddMaxNum = num;
            }
            else if(count > oddMaxSecondFreq) {
                oddMaxSecondFreq = count;
                oddMaxSecond = num;
            }
        }
        
        for(auto it = evenMap.begin(); it != evenMap.end(); it++) {
            int num = it->first; int count = it->second;
            if (count > evenMaxFreq) {
                evenMaxSecondFreq = evenMaxFreq;
                evenMaxSecond = evenMaxNum;

                evenMaxFreq = count;
                evenMaxNum = num;
            }
            else if (count > evenMaxSecondFreq) {
                evenMaxSecondFreq = count;
                evenMaxSecond = num;
            }
        }


        if(evenMaxNum == oddMaxNum) {
            return min(oddIndices - oddMaxFreq + evenIndices - evenMaxSecondFreq,
                        oddIndices - oddMaxSecondFreq + evenIndices - evenMaxFreq);
        }
        return oddIndices - oddMaxFreq + evenIndices - evenMaxFreq;
    }
};
